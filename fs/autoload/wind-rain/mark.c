// 金風細雨樓信物--風雨令
//roger && taifar
//將作為新手quest 方便新手進出風雨樓而調整 by blazakira 2011/6/25

inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIY + "風雨令" + NOR, ({"wind_rain mark","wind_rain" }));
  set_weight(5);
  set("no_sell",1);
  set("no_auc",1);
  set("no_drop",1);
  set("no_save",1);
  set("no_give",1);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "塊");
    set("long","
   風雨令，傳說中的神秘幫會「金風細雨樓」的信物，一向為各代樓主所有。
   此令足以號令武林，並可調度風雨樓中" + HIY + "「金風細雨」" + NOR + "四輩護衛，持此令者一
   向就是公認的武林盟主。改朝換代時一度下落不明，如今重出江湖，代表著
   和平盛世已經走到了盡頭，樓中風雨欲來。

   細看此令，兩面分別書著" + HIC + "「風」" + HIW + "「雨」" + NOR + "兩大字，另外有兩行小字：

              " + HIC + "不見風雨，治世有明  風雨驟遇，亂世荼靈。" + NOR + "

\n");
    set("value", 100);
    set("material", "paper");
  }
  setup();
}

int query_autoload()
{
  object me;
  me=environment(this_object());
  if(me->query("combat_exp") > 900000) return 0;
  else if(environment(this_object())->query("mark/武林盟主",1)==1) return 1;
  return 0;
}
