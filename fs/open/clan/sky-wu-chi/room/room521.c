inherit ROOM;
void create() {
	set( "short", "血痕居-五郎八卦棍" );
	set( "owner", "holeman" );
	set( "build", 10039 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room519.c",
		"south"     : "/open/clan/sky-wu-chi/room/room527",
		"north"     : "/open/clan/sky-wu-chi/room/room525",
	]) );
	set( "long", @LONG

陰陽善拆無情棍   八卦圓形要認真   兩儀截殺多生計   四象分明腳踏齊

揭法臂彈防恐漏   太極風雲閃避身   棍星槍放麒麟步   平山子午更知蹤

標龍出手如風箭   三槍下馬不能容   提攔橋力身如柱   退步連環吞吐槍

鎖喉槍法前師訓   棍法長門習短方   拆遇迫時應退步   剛柔收縮是陰陽 

平山擅打無情棍   下馬金槍見閻皇   太極分開兩邊打   運星偷進膽魂驚

提攔接轉須煞落   八卦飛開不讓情   四象上頭還有救   橫星托夾跌如龍

真真假假正門法   引起偏門策更長   跟棍打上還恐接   梅花大煞眩奇光

浪棍埋身無處用   獨地扶持取腦漿   麒麟步走如飛馬   陰陽捷打影無尋

纏枝一抽魂不在   但凡擺救煞偏門   量天尺擊橋手落   提轉正門伏死地

鎖喉槍法無些剩   拖打偏門退救長   務習純熟為根本   莫失威儀在志誠 



LONG);
	setup();
	replace_program(ROOM);
}
