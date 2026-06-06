inherit ROOM;
void create() {
	set( "short", "$HIC$星$HIY$月$HIW$閣～$HIM$相$HIR$思$HIW$居$NOR$" );
	set( "build", 12871 );
	set( "owner", "left" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room567",
	]) );
	set( "long", @LONG

                                                ﹎         .-~-_     __         
               證 盼 空            才 生    ● ﹉         {`    #  .;  `-_      
            燈 後 千 一            會 平   ▁▂▁_ ﹋      ^\    `~'   _. ;     
            半 來 金 縷   氣 心 身 相 不        ¯﹉ ﹋   / _.        <  ~\'    
         月 昏 時 遊 餘   若 如 似 思 會                 ^-~  >        ^\       
     徐  半 時    子 香   游 飛 浮    相                   /' /^╮▅/^. |       
     再  明    正 何 在   絲 絮 雲 便 思                  ~_;' ▕  ╢ |/        
  折 思  時    是 之 此            害                          ▕  ╢           
  桂           何                  相                        ●▕  ╢           
  令           時                  思                      ︽▲ ╯ ╰           
                                            _.,  -_.   -  _  ﹍ -   -﹉  -  .   

LONG);
	setup();
	replace_program(ROOM);
}
