inherit ITEM;
#include <ansi.h>
#include "../../open.h"



void create()
{
  set_name( "甕" ,({"jug"}));
  set("long","這個甕為千年金磚所製 ,看來非得找一把神兵利器才能將它打(break)開！
難不成裡面藏著傳說中死靈骨魔的珍藏寶物？ \n");
  set("unit","俱");
  set_weight(1000000);
  set("value",10000);
  setup();
}

void init()
{
         add_action("do_break","break");
}

int do_break(string str)
{
  int g,c,d,i,j;
  object cash,gold,diamond,gift1,gift2,gift3,gift4,gift5,gift6,gift7,gift8,gift9,gift0,gift10;
  object gift11,gift12,gift13;

  if (!str || str != "jug")
    return notify_fail("你要打開什麼 ?\n");
  if (!present("et-sword",this_player()) ||
      !present("dragon blade",this_player()))
  {
    return notify_fail("先找到屠龍刀和倚天劍再說吧！\n");
  }
  if (!this_player()->query_temp("ghost-quest/cankill-king"))
  return notify_fail("你又沒參予爭討死靈骨魔的行動。\n");
  message_vision(HIW"\n\n$N大喝一聲，右手持著"HIY"屠龍刀"HIW"，左手握著"HIC"倚天劍"HIW"氣勢萬千的往盒子一砍！\n",this_player() );
  message_vision(HIY"屠龍刀"HIW"與"HIC"倚天劍"HIW"融合的霸氣擊向千年金磚，迸發出令人刺眼的光芒。\n\n"NOR,this_player());
 
  gift0=new("/open/ghost-hole/obj/eq/ghost-cloak");
  gift1=new("/open/ghost-hole/obj/eq/ghost-armband");
  gift2=new("/open/ghost-hole/obj/eq/ghost-boots");
  gift3=new("/open/ghost-hole/obj/eq/ghost-armor");
  gift4=new("/open/ghost-hole/obj/eq/ghost-gem");
  gift5=new("/open/ghost-hole/obj/eq/ghost-gloves");
  gift6=new("/open/ghost-hole/obj/eq/ghost-helmet");
  gift7=new("/open/ghost-hole/obj/eq/ghost-leggings");
  gift8=new("/open/ghost-hole/obj/eq/ghost-pants");
  gift9=new("/open/ghost-hole/obj/eq/ghost-ring");
  gift10=new("/open/ghost-hole/obj/eq/ghost-shield");
  gift11=new("/open/ghost-hole/obj/eq/ghost-belt");
  gift12=new("/open/ghost-hole/obj/eq/ghost-king-tooth");

  gold = new("/obj/money/gold");
  gold->set_amount(500);
  gold->move("/open/ghost-hole/g-s06");

  cash = new("/obj/money/cash");
  cash->set_amount(50);
  cash->move("/open/ghost-hole/g-s06");

  diamond = new("/obj/money/diamond");
//  diamond->set_amount(1);
//  diamond->set_amount(1);  暫時取消掉...太好賺了 = =   3/20/2004 Firedancer
  diamond->move("/open/ghost-hole/g-s06");

  message_vision(HIY""BMAG
    "\n\n鏗鏮！甕頓時碎裂，幻化成無數道光芒....一時之間，你眼前出現黃澄澄的一片，"
    "金銀財寶就像是一堆黃金山一樣，裡頭還參雜著一些寶物。\n"NOR,this_player()); 
  
  j=random(13);   
  switch (j) {
    case 0:
      gift0->move("/open/ghost-hole/g-s06");
      break; 
    case 1:
      gift1->move("/open/ghost-hole/g-s06");
      break;
    case 2:
      gift2->move("/open/ghost-hole/g-s06"); 
      break;    
	case 3:
      gift3->move("/open/ghost-hole/g-s06");
      break;
	case 4:
      gift4->move("/open/ghost-hole/g-s06");
      break;
    case 5:
      gift5->move("/open/ghost-hole/g-s06");
      break; 
    case 6:
      gift6->move("/open/ghost-hole/g-s06");
      break; 
    case 7:
      gift7->move("/open/ghost-hole/g-s06");
      break; 
    case 8:
      gift8->move("/open/ghost-hole/g-s06");
      break; 
    case 9:
      gift9->move("/open/ghost-hole/g-s06");
      break; 
	case 10:
      gift10->move("/open/ghost-hole/g-s06");
      break; 
    case 11:
      gift11->move("/open/ghost-hole/g-s06");
      break;
    case 12:
      gift12->move("/open/ghost-hole/g-s06"); 
      break;    
    }
  destruct(this_object());
  return 1;
}
