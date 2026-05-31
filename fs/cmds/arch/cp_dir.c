//用來拷貝兩個目錄的檔案使用，目前僅給admin以上使用,以免產生不避要的問題 by bss
inherit F_CLEAN_UP;
void create()
{
        seteuid(getuid());
}
int main(object me, string arg)
{
        string dira,dirb;
        int i;

        if(!arg) return notify_fail("cp_dir 原來目錄 目標目錄。\n");

        if(sscanf(arg,"%s %s",dira,dirb)!=2)
                return notify_fail("cp_dir 原來目錄 目標目錄。\n");

        if(file_size(dira)!=-2){
                write("沒有"+dira+"這個目錄!!!\n");
                return 1;
        }
        i=sizeof(dira);
        printf("dira=%s\n",dira);
        if(dira[i]=='/') dira=dira[0..i-1];
        printf("dira=%s\n",dira);

        if(TEMP_D->cp_dir(dira,dirb))
        {
                write(dira+"->"+dirb+" !!! ok.\n");
                log_file("static/CPDIR",sprintf("%s(%s)拷貝%s到%s在%s。\n",
                        me->query("name"),me->query("id"),dira,dirb,ctime(time())));
        }
        else
        {
                write("拷貝兩目錄失敗了!!\n");
        }
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : cp_dir <欲拷貝的目錄> <目標目錄>

這個指令可以完全拷貝兩個目錄的檔案,包括子目錄及子目錄裡的檔案
目標目錄若為原本不存在的目錄的話不用事先建立, 系統會幫你建立
ex:
我想拷貝/open/ping下面所有的東西到/backup/ping裡,我就下這個指令就可以了
cp_dir /open/ping /backup/ping

目前因為仍在測試階段,所以
1.只給admin以上使用
2.你在用的時候會看到一大堆cp a->b的訊息,目錄大的話就會跑好幾頁
  可能會有些不方便不過也可以趁此看看你到底cp了那些東西
3.若有人使用發現了bug,要趕快跟我說喔!!!
在此特別感謝arthur教我使用遞迴寫這個指令

                                           bss@2000/06/17
HELP
);
    return 1;
}
