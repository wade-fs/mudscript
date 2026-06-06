// Room: /u/o/onion/room/d_room1.c

inherit ROOM;

void create()
{
	set("short", "小客廳");
	set("long", @LONG
這裡是武威鑣局瓢把子 趙鼎天的獨生女--趙淑媛所居住的小樓,裡頭有木桌木椅等
普通的家具,所有的東西都顯的很樸素,和外頭豪華的一切實在是格格不入,絲毫都不似
一個大小姐所住的地方.
    往樓上走便是趙淑媛所住的房間.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"d_room2",
  "west" : __DIR__"d_room0",
	]));
	set("objects",(["/u/o/onion/npc/squire" : 1,]));

	setup();
}

int valid_leave(object me,string dir)
 {
        object who;
        if (dir=="up" && who=present ("squire", environment(me)))
          if(!who->query_temp("unconcious"))
          return notify_fail ("婢女攔在樓梯前說道:小姐吩咐過,不想有人打擾她,"
          +RANK_D->query_respect(me)+ "還是別讓我為難吧..\n");
        return ::valid_leave(me, dir);
 }    
  
