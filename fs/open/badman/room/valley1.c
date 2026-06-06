// Room: /open/badman/room/valley1.c
// written by powell 96.4.26@FS

inherit ROOM;

void create ()
{
  set ("short", "神秘山谷");
  set ("long", @LONG
從密道鑽出來後，居然來到了這個山谷，谷中林木茂盛，鳥語
花香，可真是個人間仙境。耳中不時傳來〞吱吱〞叫的聲音，聽起
來好像是猴子的叫聲，看來這山谷可是這群猴子們的天下。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"lake5",
  "east" : __DIR__"valley2",
]));
  set("outdoors", "/open/badman");

  setup();
}
