inherit ROOM;
void create() {
	set( "short", "狂龍殿大門" );
	set( "object", ([
		"amount6"  : 1,
		"file1"    : "/open/fire-hole/obj/g-pill",
		"file10"   : "/open/mon/obj/mon-pill",
		"amount1"  : 110,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount7"  : 119,
		"amount8"  : 137,
		"file5"    : "/open/mon/obj/thousand-nectar",
		"file8"    : "/open/fire-hole/obj/w-pill",
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"file9"    : "/open/fire-hole/obj/y-pill",
		"amount3"  : 150,
		"amount4"  : 137,
		"file3"    : "/open/fire-hole/obj/p-pill",
		"file4"    : "/open/fire-hole/obj/r-pill",
		"file7"    : "/open/fire-hole/obj/b-pill",
		"amount10" : 20,
		"amount9"  : 144,
		"amount5"  : 3,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room83.c",
		"enter"     : "/open/clan/13_luck/room/room85.c",
	]) );
	set( "build", 10156 );
	set( "long", @LONG
        ◣           ◢      ▲                          
             ▆         ▆     ◤████                     
    ◢███◣▆       ▆    ◤█████     ◢███◣      
┌--◥--▼--◤-▆ ----▆---◤█████ ╯----◥--▼--◤----┐
│  ------------◥---◤--◤█████ ╯----------------┐  │
│▕             ◎ ◎██████ ╯                   │  │
│▕          ╭███╮    ██〉╯                    │  │
│▕    狂      ╰--╯           龍                 居  │  │
│▕           ▼    ▼                                 │  │  
│▕ˍˍˍˍˍ__▲  ▲ˍˍˍˍˍˍˍˍˍˍˍˍˍˍˍˍˍ│  │
└──────--◥█◤───────────────────┘ 
    在漠北黃土高原唯一的草原上，有一個傳說中的鳳凰堐，上面聽
說除了常可看到鳳凰，更住著一條龍，霸決天下的龍『　狂　龍　』
你不知為何走到這裡，突然山頂雲霧中一條張著血盆大口的龍朝你撲
過來，定神一看原來是一個橫亙山頂而下伸出來的龍頭雕像，這龍趴
在一塊寬過百丈的連山匾額，上面寫著斗大的三個字--狂龍居--還隱
隱發亮，顯示出歷史的久遠，這裡是狂龍居的入口。

LONG);
	setup();
	replace_program(ROOM);
}
