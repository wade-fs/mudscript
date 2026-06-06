// Room: /open/gsword/room/g4-4.c
inherit ROOM;

void create ()
{
  set ("short", "鐘樓頂樓");
  set ("long", @LONG
你上到了頂樓，一個青銅巨鐘掛在正中央，左首一個大木樁，往西方
望去，仙劍盡收眼底，仙劍雖然僅數十年的歷史，卻已甚具規模，你看到
西北方的遠處有個高塔，卻是從未去過，不知是否隸屬仙劍？
 
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "down" : "/open/gsword/room/g4-4.c",
]));

  set("objects", ([ /* sizeof() == 1 */
   "/open/gsword/npc/trainee-2":1,
]));

  set("light_up", 1);

  setup();
}
