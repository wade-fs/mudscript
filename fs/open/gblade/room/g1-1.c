inherit ROOM;

void create ()
{
  set ("short", "金刀門外");
  set ("long", @LONG

大門上面高高的懸著一塊琉璃黃金匾，上頭寫著『金刀門』三個斗大的字
陽光照耀下，反射出耀眼的金光，朱紅色的大門開著，門上兩個門環俱做
獅頭狀，看起來沈甸甸的，顯的氣派非凡。門兩旁各蹲著一個雕的栩栩如
生的石獅子，獅子旁站著兩名侍衛正盯著你瞧。

LONG);

  set("objects", ([ /* sizeof() == 2 */
"/open/gblade/npc/guard2" : 2,
]));
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 4 */
	"south" : "/open/port/room/r4-1",
  "enter" : __DIR__"g1-2.c",
]));

  setup();
}
 int valid_leave(object me, string dir)
 {
	if(dir=="enter"&&present("gold-blade guard",environment(me)))
  {
  if(me->query("class")=="poisoner")
	return notify_fail("金刀武士怒喝 : 魔教徒休想進去一步\n");
  if(me->query("class")=="killer")
    return notify_fail("金刀武士說道 : 幹什麼 , 想進去殺人放火嗎 ?\n");
  if(me->query("family/family_name")=="金刀門")
  return 1;
if(me->query_temp("allow-enter")==1)
return 1;
if(me->query("quests/bochen_trouble")!=1)
    return notify_fail("金刀武士攔住你的去路 ,說道 :你以為金刀門是什麼地方 ? 任你來去自如 ?\n");
   }
  return 1;
  }
