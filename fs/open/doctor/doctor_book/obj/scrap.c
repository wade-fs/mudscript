// torch
// 取得道具 之後quit 會扔在地上 沒有設定no_save時 應可存在倉庫 但是會恢復原狀 因此保留no_save 並額外找npc存放
#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("碎片", ({ "scrap" }) );
  set("unit", "枚");
  set("long","這是一枚靈魂碎片，黯淡光芒隱隱閃爍看起來似乎" + HIY + "馬上就要消失" + NOR + "的模樣，令人有些擔心，但\n"+
    "是你不清楚是哪一位大神的，因此不知道該怎麼幫助這個靈魂，不過你可以到處走訪，或者\n"+
    "某個門派正在尋找也不一定呢。\n");
  set("value",0); //靈魂無價～laugh
  set("no_save",1);
  set_weight(1000);
  setup();
}

void init()
{
  string str;
  str=query("sort"); //額外定義來改名字 //這樣的缺點在於不能使用query_autoload() 因為重登時會重新讀取預設值
  switch(str)
  {
    case "角":
      set_name(RED + "角" + NOR + "之碎片",({"spica soul splinters","spica"}));
      break;
    case "奎":
      set_name(YEL + "奎" + NOR + "之碎片",({"kui soul splinters","kui"}));
      break;
    case "井":
      set_name(MAG + "井" + NOR + "之碎片",({"jing soul splinters","jing"}));
      break;
    case "星":
      set_name(CYN + "星" + NOR + "之碎片",({"star soul splinters","star"}));
      break;
    case "麟":
      set_name(WHT + "麟" + NOR + "之碎片",({"lin soul splinters","lin"}));
      break;
    default:
      break;
  }
}

int query_autoload()
{
  return 0;
}
