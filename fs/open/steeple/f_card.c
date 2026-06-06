inherit ITEM;
#include <ansi.h>
void create()
{
set_name("挑戰晶片",({"fight_card","card"}));
set("long","一個全新的戰鬥晶片，在你通過考驗後，會自動做下記錄，
若要看最新的紀錄，請記得要到售票大廳去更新。");
set("value",0);
set("unit","片");
set("base_unit","片");
setup();
}

void init ()
{
object me=this_player();
int i=me->query("quest/start_game");
int a=i-1;
int j=me->query("quest/lose_game");
if(me->query("quest/start_game"))
        {
        set_name(HIW + "LV"+a+"  "+me->query("name")+"戰鬥晶片" + NOR,({"fight_card","card"}));
        set("long","
 
" + HIW + "▕▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▏
▕▕▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▏▏
▕▕                          火神舞  特製晶片                              ▏▏
▕▕▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▏▏
▕▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▏" + NOR + "


                   名字：" + HIW+me->query("name")+NOR + "

                   幫派：" + NOR+me->query("clan/name")+NOR + "

                   師傅：" + NOR+me->query("family/master_name")+NOR + "

                   目前挑戰樓層：第 " + HIY+i+NOR + " 樓

                   目前登記失敗次數： " + HIY+j+NOR + " 次
        ");
        }
}
