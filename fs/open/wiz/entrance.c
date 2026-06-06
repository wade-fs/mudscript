// Room: /open/wiz/entrance.c

#include <login.h>
inherit ROOM;

void create()
{
	set("short", "巫師會客室");
	set("long", @LONG
這裡是巫師和玩家聊天的地方﹐如果你有什麼意見要讓巫師們知道﹐在這裡
留言是最快的途徑﹐不過如果是對於遊戲中的問題﹐請您先確定我們提供的說明
文件裡沒有說明﹐再提出疑問﹐巫師的主要職責並不是教玩家如何玩。
    有問題是必然的事情, 但是重點在於找出解決之道, 而不是補償等等問題,
當然, 就算要補嘗玩家的損失, 請勿造成不公平現象, 最好有其他巫師在場見證
或者自行 post 之. 對於做壞事的玩家, 也請在此提出討論. 對於 bug, 請負責
的巫師盡快修正.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"fund_office",
  "west"  : __DIR__"hall1",
  "down"  : "/open/common/room/inn",
  "south" : __DIR__"area",
  "east"  : __DIR__"eq",
  "meeting" : __DIR__"meeting",
]));
  set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/server" : 1,
]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("no_magic", 1);

	setup();
	call_other("/obj/board/player_b","???");
}
