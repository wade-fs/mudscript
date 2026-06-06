// Room: /open/ping/room/f11.c ~night~(小戀)

inherit ROOM;

void create ()
{
  set ("short", "廣場");
  set ("long", @LONG

這是風行山寨內的大廣場,面積十分廣大,有幾個小囉囉到處走動,巡邏著,保護山寨的安全,
眼前有一棟三層樓高的碉堡式建築,佔地十分遼闊,整個建築物看來十分雄偉,裝飾的富麗堂,你不禁羨慕起這棟建築的主人了.你發現建築物最上方有一圈白色的裝飾品,仔細一看,竟是
一顆顆化成白骨的人頭,你不禁打個寒顫,原來這就是傳說中的風行山寨呀!!!


LONG);


  set("outdoors", "/open/ping");

  set("exits", ([ /* sizeof() == 3 */
 "south" : __DIR__"f8",
  "west"  : __DIR__"f10",
]));
 set("objects",([
"/open/ping/npc/2.c":2,
]));

  setup();
}
