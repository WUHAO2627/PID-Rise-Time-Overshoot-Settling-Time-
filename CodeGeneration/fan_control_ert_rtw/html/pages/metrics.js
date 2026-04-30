function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["fan_control_P"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control_data.c",
	size: 16};
	 this.metricsArray.var["fan_control_capi.c:mmiStatic"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control_capi.c",
	size: 184};
	 this.metricsArray.var["fan_control_capi.c:rtBlockParameters"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control_capi.c",
	size: 96};
	 this.metricsArray.var["fan_control_capi.c:rtBlockSignals"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control_capi.c",
	size: 40};
	 this.metricsArray.var["fan_control_capi.c:rtDimensionArray"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control_capi.c",
	size: 8};
	 this.metricsArray.var["fan_control_capi.c:rtDimensionMap"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control_capi.c",
	size: 16};
	 this.metricsArray.var["fan_control_capi.c:rtFixPtMap"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control_capi.c",
	size: 32};
	 this.metricsArray.var["fan_control_capi.c:rtModelParameters"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control_capi.c",
	size: 24};
	 this.metricsArray.var["fan_control_capi.c:rtSampleTimeMap"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control_capi.c",
	size: 24};
	 this.metricsArray.fcn["Fan_Controller_Exe"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control.c",
	stack: 96,
	stackTotal: 176};
	 this.metricsArray.fcn["Fan_Controller_Init"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control.c",
	stack: 8,
	stackTotal: 32};
	 this.metricsArray.fcn["Fan_Controller_terminate"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control.c",
	stack: 8,
	stackTotal: 8};
	 this.metricsArray.fcn["PID_Parameter_Adjustment"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\PID_Parameter_Adjustment.c",
	stack: 80,
	stackTotal: 80};
	 this.metricsArray.fcn["fan_control_Fan"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\Fan.c",
	stack: 72,
	stackTotal: 72};
	 this.metricsArray.fcn["fan_control_Fan_Init"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\Fan.c",
	stack: 16,
	stackTotal: 16};
	 this.metricsArray.fcn["fan_control_GetCAPIStaticMap"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control_capi.c",
	stack: 8,
	stackTotal: 8};
	 this.metricsArray.fcn["fan_control_InitializeDataMapInfo"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control_capi.c",
	stack: 8,
	stackTotal: 24};
	 this.metricsArray.fcn["fan_control_capi.c:fan_control_InitializeDataAddr"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control_capi.c",
	stack: 16,
	stackTotal: 16};
	 this.metricsArray.fcn["fan_control_capi.c:fan_control_InitializeLoggingFunctions"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control_capi.c",
	stack: 8,
	stackTotal: 8};
	 this.metricsArray.fcn["fan_control_capi.c:fan_control_InitializeVarDimsAddr"] = {file: "C:\\Work\\RD\\Projects\\Fan\\CodeGeneration\\fan_control_ert_rtw\\fan_control_capi.c",
	stack: 16,
	stackTotal: 16};
	 this.metricsArray.fcn["fmax"] = {file: "C:\\Program Files\\MATLAB\\R2024b\\polyspace\\verifier\\cxx\\include\\include-libc\\bits\\mathcalls.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["log"] = {file: "C:\\Program Files\\MATLAB\\R2024b\\polyspace\\verifier\\cxx\\include\\include-libc\\bits\\mathcalls.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sqrt"] = {file: "C:\\Program Files\\MATLAB\\R2024b\\polyspace\\verifier\\cxx\\include\\include-libc\\bits\\mathcalls.h",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="javascript:void(0)" onclick="return postParentWindowMessage({message:\'gotoReportPage\', pageName:\'fan_control_metrics\'});">Global Memory: 440(bytes) Maximum Stack: 96(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
