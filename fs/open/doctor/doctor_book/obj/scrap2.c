// torch
// 取得道具 之後quit 會扔在地上 沒有設定no_save時 應可存在倉庫 但是會恢復原狀 因此保留no_save 並額外找npc存放
#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("靈魂碎片", ({ "energy" }) );
  set("unit", "枚");
  set("long", "這是一枚靈魂碎片，但是你不清楚是哪一位大神的，不過它看起來充滿生命力。\n");
  set("value",0); //靈魂無價～laugh
  set("no_save",1);
  set_weight(1000);
  setup();
}

void init()
{
  string str;
  str=query("sort"); //這樣的缺點在於不能使用query_autoload() 因為重登時會重新讀取預設值而還原原始名稱故額外設定no_save
  switch(str)
  {
    case "角":
      set_name(HIR"角"NOR"之力",({"spica soul energy","spica"}));
      break;
    case "奎":
      set_name(HIY"奎"NOR"之力",({"kui soul energy","kui"}));
      break;
    case "井":
      set_name(HIM"井"NOR"之力",({"jing soul energy","jing"}));
      break;
    case "星":
      set_name(HIC"星"NOR"之力",({"star soul energy","star"}));
      break;
    case "麟":
      set_name(HIW"麟"NOR"之力",({"lin soul energy","lin"}));
      break;
    default:
      break;
  }
}

int query_autoload()
{
  return 0;
}
