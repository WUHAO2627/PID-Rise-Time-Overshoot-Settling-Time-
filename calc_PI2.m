function [Kp, Ki, zeta, wn] = calc_PI2(t_r, M_p, t_s)
    % 步骤1：由超调量M_p计算阻尼比zeta（仅适用于0 < zeta < 1）
    Mp_ratio = M_p / 100;  % 转换为小数
    if Mp_ratio <= 0 || Mp_ratio >= 1
        error('Overshoot should be in(0,100)%');
    end
    zeta = -log(Mp_ratio) / sqrt(pi^2 + (log(Mp_ratio))^2);  % 超调量反推公式
    
    % 步骤2：由上升时间t_r或稳定时间t_s计算自然频率wn（优先满足t_r）
    % 上升时间公式（近似）：t_r ≈ 1.8 / wn（适用于zeta≈0.7）
    wn_from_tr = 1.8 / t_r;
    % 稳定时间公式（2%误差带）：t_s ≈ 4 / (zeta * wn) → wn_from_ts = 4 / (zeta * t_s)
    wn_from_ts = 4 / (zeta * t_s);
    
    % 取两者中更合理的值（通常以t_r为主，若冲突需手动调整指标）
    wn = (wn_from_tr + wn_from_ts) / 2;  % 折中处理，避免指标矛盾
    
    % 步骤3：根据风扇线性模型传递函数，推导PI参数
    % 风扇线性模型：G(s) = 2.857/(s + 0.2334)
    % 闭环特征方程：s² + (0.2334 + 2.857*Kp)s + 2.857*Ki = s² + 2*zeta*wn*s + wn²
    Kp = (2*zeta*wn - 0.2334) / 2.857;  % 比例系数
    Ki = (wn^2) / 2.857;                % 积分系数
    
    % 确保参数非负（避免控制器不稳定）
    Kp = max(Kp, 0);
    Ki = max(Ki, 0);
end