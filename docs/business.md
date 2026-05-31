「業務邏輯」層面：                                        
                                                                                                                                                 
   1. 鎖定熱點檔案：進一步分析 fs/obj/user.c 與其繼承的 condition.c，排查是否存在潛在的循環呼叫。                                                
   2. 進階 Memory Profiling：我可以使用 Go 的 pprof 工具來精確定位這段 Legacy 代碼在啟動後，究竟是哪類物件或函式瘋狂佔用記憶體。                 
   3. 針對性關閉：是否要針對 user.c 的心跳函式進行暫時性的剖析，確認是否因為 Legacy Code 的某些邏輯在新的 Driver 下觸發了意料之外的 CallOut      
      或循環遞迴？
