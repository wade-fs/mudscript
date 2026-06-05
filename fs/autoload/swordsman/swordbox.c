#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
set_name("" + HIC + "聖劍劍匣" + NOR + "",({"swordbox","sword"}));
set_weight(7000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "把");
set("long",
"一個刻畫著神秘花紋的劍匣,劍匣縫細中隱隱約約傳出讓人敬畏的氣息。\n");
set("value",0);
set("material", "crimsonsteel");
   set("no_drop", 1);
   set("no_give", 1);
   set("no_get", 1);
   set("no_auc", 1);
   set("weapon_prop/sword",10);
   set("rigidity",100);
}
init_sword(110);
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
     if( query("equipped") )
     {
message_vision(HIC + "$N將其身後厚重的劍匣中抽出" + HIR + "日" + HIB + "月" + HIW + "神器" + HIC + ",頓時日月並現於天際,並將其靈氣注入" + HIR + "聖器中" + NOR + "\n",this_player());
set_name("" + HIR + "日" + HIB + "月" + HIW + "神器" + NOR + "",({"sun_moon_sword","sword"}));
set("long",
"由朝陽古闕與拜月幽劍兩把礦世神器所合鑄成的劍.....半邊劍身呈深紅色
另半邊則會為陰藍色,完全顯現出這把神器的特性-剛柔並濟-。\n");
}
}
int do_unwield(string str)
{
   if( str=="all" || str=="sword" || str=="sun_moon_sword")
     if( query("equipped") )
     {
        message_vision(HIW + "$N將手中聖器向後一丟...聖器乎有靈性一般,自動回歸劍匣內。\n",this_player());
set("long",
"一個刻畫著神秘花紋的劍匣,劍匣縫細中隱隱約約傳出讓人敬畏的氣息。\n");
set_name("" + HIC + "聖劍劍匣" + NOR + "",({"swordbox","sword"}));
     }
}
int query_autoload()
{
   return 1;
}


