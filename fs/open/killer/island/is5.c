// Room: /u/u/unfinished/room/is5.c
inherit ROOM;

void create ()
{
  set ("short", "沙灘");
  set ("long", @LONG
你正處於小島的東南角, 站在亮白如雪的沙灘上欣賞無邊際的海景, 不經令
你感到格外的神清氣爽, 所有的煩惱及不愉快都隨著輕微的海風拋諸於腦後. 殺
氣, 怒意在這美麗的沙灘上早已消失無形, 讓你幾乎忘了自己的身分. 北方是沙
灘, 西方是船隻擱淺處.
LONG);

  set("outdoors", "/u/u");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"is8.c",
  "west" : __DIR__"is4",
]));

  setup();
}
