// beck.c
//需在房間設定資源種類才可以fill 並非在房間內的物件裡設定 by blazakira
//因為不能sac 所以基本上 本次的quest rb之後只能解一個人(估計) 例外 將水喝光
//可選擇 裝水的次數少 但是水缸的個數多的方式分散解謎的範圍

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
int do_fill();

void create()
{
	set("no_sac", 1);
	set("no_get", 1);
	set_name("水缸",({"water vat","vat"}));
	set("long","一個沈重的大水缸，似乎可以藉由某種東西倒水(pour)進去。\n");
	set("液體", ([ //set液體(含以下參數)這部份為drink所使用 而fill 則是以房間的參數為主 這兩部份不同
		"種類": "水",
		"名稱": "清水",
		"剩": 0,
		"止渴" : 30,//限制恢復口渴範圍固定為30
	]) );
	setup();
}

void init()
{
  environment(this_object())->set("no_reset",1); //將該房間設定為不會隨著15分鐘而重生 為了限制玩家在12小時內的解謎人數
  add_action("do_fill","fill");
}

int do_fill(string arg)
{
  if (!arg ) return 0; //沒有指定對象 則不做動作>>>arg不存在
  message_vision(HIY + "當$N伸手想掬起一些水時，突然一旁有人重重地拍了一下$N的腦袋說﹕就在缺水了，還讓你裝水勒。\n" + NOR,this_player());
  return 1;
}
