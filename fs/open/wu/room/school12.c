// Room: /u/d/devils/school12.c

inherit ROOM;

void create()
{
	set("short", "地牢");
	set("long", @LONG
你走進一間陰暗潮濕的小房間，剛進房間時你覺得一片漆黑，等你
眼睛慢慢習慣黑暗後，你赫然發覺有個人被鎖在這裡，他四肢被鐵鍊鎖
住，琵琶骨也被鐵鍊貫穿，他低著頭動也不動，令你不知他是死是活..
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"school11",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/jen2" : 1,
]));
        setup();
}
