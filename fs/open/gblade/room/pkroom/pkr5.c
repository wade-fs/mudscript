// pkr5.c by konn
inherit ROOM;

void create()
{
        set("short", "第一武道館");
	set( "build", 12 );
        set("long", @LONG
這裡是天下第一武道會館, 抬頭一看, 你的頭上有一塊刻著「天下第一堂」
的檜木扁額, 在你的正前方是一個長寬各百米的比武教練場, 你的右手邊陳
列著許\多種兵器, 有弓、弩、鎗、刀、劍、矛、盾、鉞、斧、戟、鞭、戩、
撾、殳、叉、爬頭、綿繩套索、白打等十八種兵器隨你挑選, 在場子的左邊
站著一個身穿青布衣, 腳上套著僧侶鞋的壯漢, 他就是比武大會的主持人。
看著場子裡幾個大漢正在比試, 你不禁也想下去和他們較量較量。



LONG);
        set("exits", ([ /* sizeof == 4 */
            "north" : __DIR__"pkr2",
            "east"  : __DIR__"pkr6",
            "west"  : __DIR__"pkr4",
            "south" : __DIR__"pkr8",
      ]));

        set("objects", ([ /* sizeof == 1 */
            "/open/gblade/npc/officer1" : 1,
      ]));
set("no_scale",1);
        set("no_transmit", 1);
        set("light_up", 1);
        set("no_clean_up",1);
        setup();
 enable_commands();

}
//玩家反應訊息會有問題，先關閉等找到問題後再開放吧！
void receive_message(string msgclass, string msg)
{

    tell_room("/open/gblade/room/pkroom/lookpkroom",msg);
}
