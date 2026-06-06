// Room: /u/c/cyw/room/r1
//暫時沒使用 故而先by pass by blazakira 2011/8/21

inherit ROOM;

void create ()
{
  set ("short", "忍術練習場");
  set ("long", @LONG
這是女影門平時練忍術的地方,四周不斷的有穿著黑衣裝的忍者
在練習著密術,從他們婀娜多姿的體態可以看出黑衣裝內應該是女人
,在一棵百年神樹下有個漂亮的女子在傳授這些黑衣人武功你往她的
方向走去一陣陣讓人心神為之一蕩的幽香傳入你的鼻中,原來她正是
女影門的最高首領,真是人如其名是個香甜可愛的美女。
LONG);

  set("objects", ([ /* sizeof() == 1 */
//    "/open/japan/npc/master.c" : 1,
  ]));
  set("light_up", 1);
  set("outdoors", "/u/c/cyw/room");
  set("exits", ([ /* sizeof() == 1 */
    "west" : "/u/c/cyw/workroom.c",
  ]));

  setup();
}
