// Room: /open/soulin/room/D01.c

inherit ROOM;

void create ()
{
  set ("short", "寺門");
	set( "build", 1 );
  set ("long", @LONG
	雄偉壯闊的寺門，顯示了少林寺數百年來屹立不倒
	的大家風範，在武林中說到少林寺莫不人人翹指稱
	讚，是故有人傳稱少林武功乃武林之首，由其數百
	年來屹立不倒的氣勢看來也頗有幾分可信度。


LONG);

  set("objects", ([ /* sizeof() == 1 */
"/open/bonze/npc/konwun":1,
]));
  set("outdoors", "/open/soulin");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r8",
  "enter" : __DIR__"s02",
]));

  setup();
}
int valid_leave(object who, string dir)
{
  if( present("kon wun", this_object()) ) {
if(who->query("bellicosity") > 700 && who->query("id")!="swordsman") {
        return notify_fail("空聞彎腰合十對你微笑道: 少林寺為佛門淨地，施主殺孽之氣太重，還請留步。\n");
   }
  }
 
  return ::valid_leave(who, dir);
}
