#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        seteuid(getuid(me));
 
        if (me->query_temp("brief_mode")) {
          me->delete_temp("brief_mode");
          write ("長訊息糢式。\n");
        }
        else {
          me->set_temp("brief_mode",1);
          write ("短訊息糢式。\n");
        }
        return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式 : brief
指令說明 :
           這個指令可以讓你以長訊息模式或短訊息模式顯示你所看到的東西。
           它是個開關，當你處於長訊息模式時，會切換到短訊息模式，反之
           亦然。也就是會在此兩種模式之間切換。
HELP
    );
    return 1;
}
