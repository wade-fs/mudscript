#include <ansi.h>
inherit ROOM;
string sign();

void create()
{
	set("short",BBLU+YEL + "震邪道" + NOR);
	set("long",@LONG
除了你來時的通道外, 四處都已經被磚瓦給封死了, 地上佈滿了
砂土, 除此之外, 在沙堆中, 有一個告示牌(sign)...
LONG);
	set("exits",([
"north":__DIR__"e01",
]));
	set("item_desc",([
"sign": (: sign :),
]));
	set("no_transmit",1);
	setup();
}

string sign()
{
	object me=this_player();

	tell_object(me,"\n斑黃的木板寫著：此路只為有緣者開...\n");
	call_out("move",1,me);
	return "\n";
}

int move(object me)
{
	me=this_player();
	if(!me->query_temp("evil/d_enter"))
		return notify_fail(" 儒非有緣人...\n");
	message_vision(YEL + "地下的塵土突然開始移動～

$N腳下的土開始下陷，$N整個人被土堆吞噬了...\n\n" + NOR,me);
	me->move(__DIR__"e03");
message_vision(HIY + "\n〔碰〕的一聲巨響～$N掉了下來！\n" + NOR,me);
	return 1;
}
