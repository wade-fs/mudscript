// Room: /open/common/room/inn.c babe 塗鴉.. cc..
//改為室外 因為不希望玩家在此房間蹲內力 by blazakira 2010/10/24
//增加進入房間的阻擋 by blazakia 2011/10/29

inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "狂想空間入口處");
  set( "build", 1670 );
  set ("long", @LONG

歡迎各位來到狂想空間的世界,希望這裏能給你不同的發現!!! :)
新手請多多使用 help 指令哦~~~~~ :)

 往上走就是狂想空間幫派言論廣場。
 往西為狂想技能建言的言論廣場。
 往東為狂想玩家申請備份檔案的地方。
 往南為狂想制度建言的討論區。
 往北為違反狂想空間制度的公佈欄。
 往東北方為歷代狂想巫師紀念榜。
 往下走你將會正式進入狂想空間的世界。

LONG);

set("objects", ([ /* sizeof() == 3 */    
"/obj/ballot.c":1,     
"/open/clan/area/killer-wu":1,     
"/open/tailong/npc/quest_girl":1,
]));
  set("exits", ([ /* sizeof() == 8 */
  "northeast" :"/open/common/room/sp_room.c",
  "carving" :"/open/main/statue/cgyroom.c",
  "statue" :"/u/w/wade/statue",
  "newhand" : "/open/newhand/newhand",
  "up" : "/open/clan/area/home/clan",
  "south" : "/open/wiz/fsroom",
  "down" : "/open/trans/room/room4",
  "east" : "/open/wiz/restore",
  "north" : "/open/wiz/fsroom2",
  "west" : "/open/wiz/skroom",
]));
  set("outdoors", "/open/common");
  set("valid_startroom", 1);
  set("light_up", 1);
  set("no_fight", 1);
  set("no_sac", 1);
  setup();
  load_object("/obj/board/news_b.c");
}
// 以免有 pker 用 sha-array 在此 pk....add by Daniel
// 加入 search , 為進入 train_yard的路 add by Anmy 98/5/26 
void init()
{
  add_action("do_team","team");
}

int do_team()
{
  object me=this_player();
  tell_object(me, "老兄...你太狠了吧!想趕盡殺絕喔？\n");
  return 1;
}
/*
int do_search(string str)
{
  object me;

  me=this_player();
  if( str != "hole" )
return notify_fail("不要在地上亂爬啦？\n");
tell_room(this_object(),"$n找到一個秘洞, 就往洞內一鐕。\n",me);

message_vision("$n本來還好好的，一瞬間$n忽然消失在你眼前。\n",me,me);
  me->move("/u/a/anmy/room/train_room");
  return 1;
}
*/
int valid_leave(object me, string dir)
{
  if (dir=="statue" && me->query("mystery")) //如果要往south離開 且 有mark ("mystery") 時 阻擋之!
//  if(!wizardp(me)) //本次設定只針對npc 所以不影響巫師行動
    return notify_fail("STOP!\n");
  return ::valid_leave(me,dir); //為valid_leave(me,dir)函數的結尾
}
