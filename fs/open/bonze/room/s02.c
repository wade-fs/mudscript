// Room: /open/soulin/room/s02.c

inherit ROOM;

void create ()
{
  set ("short", "少林寺前廣場");
  set ("long", @LONG
	
這裡是少林弟子們練功的場所，四周擺滿了練功的器具。從整齊劃一
的口令聲，還有一旁木人上面傷痕累累的痕跡可以看的出來少林弟子
們的認真及努力。你心想若有機會和他們切磋切磋對自身武藝也有增
進。若繼續往北邊走即進入大雄寶殿。

LONG);

  set("outdoors", "/open/soulin");
  set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"D01",
  "north" : __DIR__"s05",
  "east" : __DIR__"s03",
  "west" : __DIR__"s01",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/main/npc/forceman.c" : 1,
]));
  

  setup();
}
int valid_leave(object who, string dir)
{
if(dir == "out" && who->query("id")=="clear man") {
        return notify_fail("空聞彎腰合十對你微笑道: 少林寺為佛門淨地，施主殺孽之
氣太重，還請留步。\n");
   }
 
  return ::valid_leave(who, dir);
}

