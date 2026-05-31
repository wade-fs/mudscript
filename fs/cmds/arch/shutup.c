inherit F_CLEAN_UP;

int main(object me,string arg)
{
        string str,onoff,name,reason;
        object ob;
        if(!arg||arg=="") return notify_fail("你要讓誰閉嘴或恢復原狀?\n");
  if(sscanf(arg,"%s %s",str,onoff)!=2)
                return notify_fail("指令格式: shutup <target> <on/off>\n");
        if(!ob=find_player(str)) return notify_fail("沒有這個人喔.\n");
if(ob==me) return notify_fail("自己買塊膠布貼起來吧..\n");
        if(onoff!="on"&&onoff!="off")
                return notify_fail("指令格式: shutup <target> <on/off>\n");
        if(wiz_level(me)<=wiz_level(ob))
return notify_fail("叫老大閉嘴?.瘋了嗎????.\n");
        if(onoff=="on") {
                ob->set("shutup",onoff);
                write("你取消了"+ob->name()+"公開頻道的權利.\n");
log_file("static/SHUTUP", sprintf("[%s] %s shutup <%s> .\n",
ctime(time())[0..15], geteuid(this_player(1)),ob->query("id")));
                return 1;
     }
        ob->delete("shutup");
        write("你開放"+ob->name()+"公開頻道的權利.\n");
log_file("static/SHUTUPO", sprintf("[%s] %s shutup <%s> off.\n",
ctime(time())[0..15], geteuid(this_player(1)),ob->query("id")));
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式: shutup <target> <on/off>

這項指令可以令一個玩家失去使用頻道的權利.
shutup <target> on 時, 代表關閉對方的頻道, 也就是不讓對方使用頻道.
shutup <target> off 則是恢復原狀.
HELP);
        return 1;
}

