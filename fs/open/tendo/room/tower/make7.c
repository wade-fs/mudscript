
inherit ROOM;

void create()
{
	set("short", "鑄造廬");
	set("long", @LONG
原來這裡是一間打鐵鋪子，從火爐中冒出的火光將牆壁映得通紅，
屋子的角落裡堆滿了各式鐵器的完成品或未完成品，像是鋤頭、鐵鎚、
鏟子、劍、弓、刀、鞭等等。屋內有位老者正在鑄造一把鋤頭，叮叮噹
噹的聲音敲得滿屋子響。你發現有張紙(paper)貼在牆壁上。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "paper" : "白紙上龍飛鳳武地寫著幾個大字﹕

   □□□ 鑄造 □□□
        鑄造所需要的條件包括 1 . 錢 2 . 礦 3. 年齡須達下限
        4 . 體力內力與時間  5 . 經驗值須達下限
        鑄造的指令有 :
        1 . 鑄造 : 請打 found <武器種類> by <礦物>
                   <武器種類> : sword blade stabber bow unarmed stick..
        2 . 命名 : 請打 setname <武器> <名字>
                   <名字> : 可以參考 nick 來更名字，不過需要本人與鑄劍師
                            一起才可以更名。
        3 . 索物 : 請打 getweapon by <武器單子>
        目前開放鑄造的武器，只是一種實驗性質的東西。跟以往的武器是有所不
        同的，可隨著你的經驗值增加，而慢慢的增加武器的傷害力。而護具的鑄
        造尚在研發中、、、、、、、、、
        
             
",
]));
	set("exits", ([ /* sizeof() == 1 */
  "down" : "/open/tendo/room/tower/make5",
]));
set("objects", ([ /* sizeof() == 1 */

]));
 set("light_up", 1);

	setup();

}
