inherit ROOM;

void create ()
{
  set ("short", "大雄寶殿");
  set ("long", @LONG
在這裡的正中央,有一座釋迦牟尼佛雕像(budda statue),也就是天
龍寺的大佛,聽說向這尊佛像祈禱(pray)能有平息殺意的功用,不知是
真是假,你不妨試試看。
LONG);

 set("item_desc", ([ /* sizeof() == 1 */
"budda statue" : "
這是天龍寺的大佛像,周圍發散出金光,看著它你覺得自己好像
身處西方極樂世界一樣..................................
這尊大佛是一位朱姓和尚以自己的面貌來鑄造的, 你一看到就
有一種想扁他的感覺......
",
]));


  set("exits", ([ /* sizeof() ==  */
  "east" : __DIR__"aa43",
  "south" : __DIR__"aa39",
  "west" : __DIR__"aa41",
]));
}
