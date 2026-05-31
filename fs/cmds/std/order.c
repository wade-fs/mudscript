// 重新改寫 order by swy
inherit F_CLEAN_UP;
#include <ansi.h>
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
string dest,cmd,verb,act;
object ob;
if( me != this_player(1) ) return 0;
if( me->query("class")!="blademan" )
return notify_fail("你不是刀客無法駕御馬。\n");
if( me->query_skill("riding",1) < 70 )
return notify_fail("你的馬術太低，不能控制馬唷。\n");
if( me->query_temp("is_riding") != 1 )
return notify_fail("你沒騎馬如何能駕御馬呢？\n");
/* if(!(me->query("id") == "alucard" || me->query("id") == "vigel"))
return notify_fail("目前不開放刀客order功\能\n");  */
if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
return notify_fail("指令格式 : order <馬馬> to <動作>\n");
if( !(ob = present(dest, environment(me))) )
return notify_fail("這裡沒有 "+dest+"。\n");
if( !living(ob) )
return notify_fail("等你的馬醒吧。\n");
if(me->query("id") != ob->query_temp("my_boss"))
return notify_fail("別傻啦，牠又不是你的馬。\n");
if(sscanf(cmd,"%s %s",verb,act)) {
if(verb=="save"||
verb=="do"||verb=="wield"||verb=="set"||verb=="join") 
return notify_fail("沒有這種指令！\n");
}
if(cmd[0..3]=="quit") return notify_fail("沒有這種指令！\n");   
if(cmd[0..3]=="save") return notify_fail("沒有這種指令！\n"); 
if(cmd[0..3]=="join") return notify_fail("沒有這種指令！\n");
if(cmd[0..3]=="team") return notify_fail("沒有這種指令！\n");   
message_vision(HIC"$N用馬術駕御馬兒，達到人馬合一！\n"NOR,me);
message_vision(HIC"馬兒聽到指揮而作出"+cmd+"的動作。\n"NOR,me);
ob->force_me(cmd);
if(verb=="k"||verb=="ki"||verb=="kil"||verb=="kill"||
verb=="f"||verb=="fi"||verb=="fig"||verb=="figh"||verb=="fight")
{ me->force_me(cmd); } 
return 1;
}

int help(object me)
{
write(@Help

指令格式 : order <馬馬> to <動作>

能駕御馬馬的指令須要馬術 70 級

Help);
return 1;
}
