// Room: /open/gsword/room/eghouse2.c
inherit ROOM;

void create()
{
  set ("short", "寢居");
  set ("long", @LONG
這是劍派新進們的寢居，由於剛拜入門下，身分地位較低，因此這
寢居也格外的簡陋，一張見方的大通鋪，幾張快垮的竹椅，即是寢
居的全部。南邊是輩分較高的師兄們的住所。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"eghouse3",
  "north" : __DIR__"eghouse1",
]) );

  setup();
}
