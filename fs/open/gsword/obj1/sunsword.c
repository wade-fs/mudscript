#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit SWORD;
object ob;
void create()
{
set_name("連陽真劍",({"sevensun_sword","sword"}) );
set_weight(9000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "把");
set("long",
"據說此劍為軒轅劍仙的配劍，其劍身成透明，只見劍身上鑲有七色寶珠
並有紅色之聖痕文字，將此劍的神祕性又增加了一成。\n");
set("value",10);
set("material", "crimsonsteel");
set("rigidity",200);
       set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
       set("no_drop",1);
       set("no_sec",1);
       set("no_save",1);
set("wield_msg", "$N拔出$n,，瞬時劍身上的七色寶珠突然發出七色光華，使人精神為之一振。\n");
set("unwield_msg", "$N將手中$n收回身後劍鞘，頓時七色靈光消失無蹤。\n");
set("weapon_prop/sword",10);
}
init_sword(99);
setup();
}
void init()
{
     add_action("do_wield","wield");
     add_action("do_unwield","unwield");
}
int do_wield(string str)
  {
 ::wield();
   if(query("equipped"))
{
ob=this_player();
message_vision("$N手握仙劍連陽，只見七色聖光環繞在$N身邊。\n",this_player());
       set_heart_beat(1);
     }
}
int do_unwield(string str)
{
if(query("equipped")) {
message_vision("$N將仙劍連陽放下，七色聖光頓時消失無蹤....\n",this_player());
        set_heart_beat(0);
}
}
void heart_beat()
{
  object *enemy;
object victim;
  int i,j,sword;
  sword=ob->query_skill("sword",1)/5;
if ( !objectp(ob) )
        {
        set_heart_beat(0);
        return;
        }

if( ob->is_fighting() && query("equipped") )
{
if( sword > random(100) ) {
message_vision(HIW + "由於受到$N內力的召喚，藏身於聖劍七色寶珠中之七劍劍靈分別由劍中寶珠竄出\n並依$N的精神而擺\出仙劍劍陣之禁斷八卦遊龍陣只見\n" + HIR + "$N仰天長嘯，催動八卦遊龍陣使出驚世駭俗的仙劍劍陣至極絕招\n" + NOR,ob);
message_vision(HIW + "\n\t\t『" + HIR + "～禁～斷～連～陽～七～訣～斬" + HIW + "』\n\n" + NOR,ob);
message_vision(HIR + "此招一出，驚天動地，傳說自仙劍創派以來從未被使用過!!\n" + NOR,ob);
message_vision(HIB + "\n烈陽劍靈狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第一式" + HIW + "『" + HIB + "烈陽" + HIW + "』" + HIB + "!!\n" + NOR ,ob);
message_vision(HIR + "\n殘陽劍靈狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第二式" + HIW + "『" + HIR + "殘陽" + HIW + "』" + HIR + "!!\n" + NOR ,ob);
message_vision(HIW + "\n豔陽劍靈狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第三式" + HIW + "『豔陽』!!\n" + NOR,ob);
message_vision(HIM + "\n暖陽劍靈狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第四式" + HIW + "『" + HIM + "暖陽" + HIW + "』" + HIM + "!!\n" + NOR ,ob);
message_vision(HIC + "\n冬陽劍靈狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第五式" + HIW + "『" + HIC + "冬陽" + HIW + "』" + HIC + "!!\n" + NOR ,ob);
message_vision(HIG + "\n朝陽劍靈狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第六式" + HIW + "『" + HIG + "朝陽" + HIW + "』" + HIG + "!!\n" + NOR ,ob);
message_vision(HIY + "\n夕陽劍靈狂性驟起，口中喃喃有辭，使出仙劍禁斷之連陽七訣第七式" + HIW + "『" + HIY + "夕陽" + HIW + "』" + HIY + "!!\n" + NOR ,ob);
message_vision(HIW + "\n七道劍虹同時激空而出，「七陽連天」在空中織成一道虹網！\n" + HIG + "而主陣的$N縱身一躍，凝氣準備發出最後一式以完成這驚天地動的一擊！\n" + NOR,ob);
message_vision(HIW + "\n只見$N狂性驟起 ,大喝一聲『" + HIR + "劍影連陽，七陽連天』!!\n" + NOR,ob);
message_vision(HIW + "$N的七陽連天氣勢澎礡，激發了先前仙劍禁斷之連陽七訣的七股剛柔並濟的劍虹\n只見虹氣嘯天，滿天劍影，陣內敵人皆受重創\n" + NOR,ob);

enemy=ob->query_enemy();
i=sizeof(enemy);
for(j=0;j<i;j++){
 enemy[j]->receive_damage("kee",500);
 enemy[j]->start_busy(2);

COMBAT_D->report_status(enemy[j],0);
}
}
}
return;
}
