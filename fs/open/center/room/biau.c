// Room: /u/p/powell/room/biau.c

inherit ROOM;

void create ()
{
  set ("short", "鑣局");
  set ("long", @LONG
這是武威鑣局的總行, 但是因為年代久遠, 卻只有一間大廳, 
其實生意如此之好, 幾乎是馬不停蹄, 多於的房間老早就搬到蜀山
去了, 原因只是最近戰亂頻仍, 人人朝不保夕, 老鑣頭也因此不打
算整修這兒, 據說, 武威鑣局生意日榮, 黑白兩道都很吃的開, 因
這附近的路似乎就是為武威鑣局而開設的, 連對面也因此聚集了世
上最有信譽的車馬行. 聽說車馬行的老闆跟老鑣頭當年曾經共同闖
蕩江湖尋寶, 可是不知實情是怎樣, 也許你可以多打聽打聽哦.
    西邊的出口是通往專門處理文書的房間。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road3",
  "west" : __DIR__"mail",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/questsfan/npc/assistant.c" : 1,
  "/open/center/npc/mercenary.c" : 2,
]));
  set("light_up", 1);

  setup();
}
