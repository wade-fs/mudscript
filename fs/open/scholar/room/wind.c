inherit ROOM;

void create ()
{
  set ("short", "風室圖書館");
  set ("long", @LONG
這裡是存放大自然中有關風之奧秘的書房，記載醫學，算命，文
學，邏輯．．等，你想知道或解決的疑難問題，在這裡似乎都可以找
到滿意的答案，許多儒門弟子也常來此翻閱書籍。由於書籍繁多此地
又分東南西北四堂，以便尋查。
LONG);

  set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"wind_n.c",
  "south" : __DIR__"wind_s.c",
  "west" : __DIR__"wind_w.c",
  "east" : __DIR__"wind_e.c",
  "southwest" : __DIR__"r11.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar5.c" : 1,
]));

  setup();
}
