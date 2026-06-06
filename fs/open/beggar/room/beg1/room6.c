// Room: /u/g/guetenr/beggar/room/beg1/room6.c
inherit ROOM;

void create ()
{
  set ("short", "茶水小棚");
  set ("long", @LONG
坡上一頂灰褐色的布棚，斜挑起一小方天地，幾張桌椅泰半時間任憑東
風坐臥，一塊洗得泛白的灰白幡子綴著流蘇似的角邊，上頭單大大寫了個『
茶』字，原是座不起眼的茶棚；布棚旁邊一棵白色曼陀羅花，疏疏落落開著
花朵，猶如一個個瓷風鈴在風中響著琳瑯，伴著茶棚主人歸隱似地守著這草
坡。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room5.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/beg1.c" : 1,
]));
  set("outdoors", "x");

  setup();
}
