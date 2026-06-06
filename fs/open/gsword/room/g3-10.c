// Room: /open/gsword/room/eghouse2.c
inherit ROOM;

void create ()
{
  set ("short", "寢居");
  set ("long", @LONG
這是劍派新進們的寢居，由於剛拜入門下，身分地位較低，因此這
寢居也格外的簡陋，一張見方的大通鋪，幾張快垮的竹椅，即是寢
居的全部。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : "/open/gsword/room/g3-8.c",
]));
  set("objects",([
     "/open/gsword/npc/boy-2":2,
      ]));

  setup();
}
