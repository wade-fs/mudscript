// Room: /open/hall/h_room2.c
inherit ROOM;

void create()
{
        set("short", "捕頭統領─冷面煞之廂房");
        set("long", @LONG
這兒是總衙捕頭統領─冷面煞的廂房，一張不起眼的桌子，桌旁散
亂擺著幾張木椅，仔細一瞧..桌上有一排清晰可見的掌印，你驚想：如
仔細一瞧桌上有一排清晰可見的掌印，你驚想：如果如果這掌印是落在
你的腦袋瓜子呢??! 牆上掛著一幅畫，畫的左上角題著兩句詞：兩情若
是久長時，又何必朝朝暮暮。
LONG);
        set("exits", ([ /* sizeof() == 1 */
  "south":__DIR__"h_room10",
]));
        set("objects", ([ /* sizeof() == 1 */
        "/open/hall/npc/face":1,
]));

        setup();
}
