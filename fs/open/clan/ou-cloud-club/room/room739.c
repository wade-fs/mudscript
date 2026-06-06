inherit ROOM;
void create() {
	set( "short", "飄零ソ森" );
	set( "object", ([
		"file2"    : "/open/mon/obj/thousand-nectar",
		"amount4"  : 500,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount6"  : 1746,
		"amount2"  : 549,
		"amount10" : 1,
		"file5"    : "/open/fire-hole/obj/r-pill",
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/open/killer/obj/atman_pill",
		"amount5"  : 17,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 332,
		"amount3"  : 493,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/open/mon/obj/mon-pill",
		"amount7"  : 650,
	]) );
	set( "build", 10092 );
	set( "light_up", 1 );
	set( "owner", "nao" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room736",
	]) );
	set( "long", @LONG
                                                                                
                                 ▍            . .     ρ.                      
          葉子，是不會飛翔的翅膀 ▍         ..     σ.         ρ .             
　  　　　翅膀，是落在天上的葉子 ▍     .   ρ.        .                        
　　  　　天堂，原來應該不是妄想 ▍        .       .ρ.                         
  只是我早已遺忘當初怎麼開始飛翔 ▍   σ.                                       
                                ▍孤單，是一個人的狂歡                          
                       .  .σ   ▍狂歡，是一群人的孤單                          
                    σ.         ▍愛情，原來的開始是陪伴                        
                     .ρ .      ▍但我也漸漸地遺忘當時是怎樣有人陪伴            
         .σ  .                 ▍Pictured by dailta                            
                                                                     

LONG);
	setup();
	replace_program(ROOM);
}
