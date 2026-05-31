// 清除太久沒上線的玩家 by ACKY

inherit F_CLEAN_UP;

#define	DAY	365 // 超過 DAY 天沒上線

int check( string arg );
int help( object me );
 
int main( object me, string arg )
{
	int o, sum;
	string *dir, *dir2;
	
        seteuid(getuid());       
        sum = 0;
               
        if( !arg )
        	return help(me);

        if( arg == "all" ) {
		dir = get_dir( "/data/login/" );
		for( o=0; o<sizeof(dir); o++ )
                	sum += check( dir[o] );
                write( "目前總共有 "+ sum +" 位玩家。\n" );
		return 1;
	}

	if( arg == "count" ) {
		dir = get_dir( "/data/login/" );
		for( o=0; o<sizeof(dir); o++ ) {
			dir2 = get_dir( "/data/login/"+ dir[o] +"/" );
                	sum += sizeof( dir2 );
                }
                write( "目前總共有 "+ sum +" 位玩家。\n" );
		return 1;
	}

	check( arg );

	return 1;	
}

int check( string arg )
{
	object ob;
	string *user, id, id_tmp;
	int i, j, k, sum, now, count;

	count = 0;
	now = time(); 
	user = get_dir( "/data/user/"+arg+"/" );
	sum = sizeof( user );

        printf( "處理中, 請稍後...\n" );
	for( i=0; i<sum; i++ ) {
                reset_eval_cost();
		id = user[i][0..sizeof(user[i])-3];
		if( find_player( id ) )
			continue;
                if( (string)SECURITY_D->get_status(id)!="(player)" )
			continue;
		if( !ob = FINGER_D->acquire_login_ob( id ) ) {
			printf( "檔案 %s 有問題, 系統將其刪除。\n", id );
			k=0;
			for( j=0; j<sizeof(id); j++ )
				if( id[j] == '.' ) {
					k++;
					if( k==2 )
						id_tmp = id[0..j] + "*";
				}
			write( "檔案 "+ id_tmp +" 並非正常存檔, 請檢查。\n" );
			rm( "/data/user/"+arg+"/"+id+".o" );
			rm( "/data/login/"+arg+"/"+id+".o" );
			rm( "/data/backup/user/"+arg+"/"+id+".o" );
			rm( "/data/backup/login/"+arg+"/"+id+".o" );
			rm( "/data/backup2/user/"+arg+"/"+id+".o" );
			rm( "/data/backup2/login/"+arg+"/"+id+".o" );
			rm( "/data/sig/"+arg+"/"+id+".sig" );
 			rm( "/data/mail/"+arg+"/"+id+".o" );
			
 			count++;
		}
		if( objectp(ob) ) {
			if( ob->query("id")=="amandy" )
				ob->delete("ok_ip");
			if ( (now-ob->query("last_on"))/86400 > DAY )	{
				printf( "%s(%s) 已經超過 "+ DAY +" 天沒上線, 系統將其資料刪除。\n", ob->name(), ob->query("id"));
	 			if( ob->query("clan") )
	 				CLAN_D->clan_promote( ob->query("clan/id"), ob->query("id"), "banish", ob->query("clan/bank") );
				rm( "/data/user/"+arg+"/"+id+".*" );
	 			rm( "/data/login/"+arg+"/"+id+".*" );
	 			rm( "/data/backup/user/"+arg+"/"+id+".*" );
	 			rm( "/data/backup/login/"+arg+"/"+id+".*" );
	 			rm( "/data/backup2/user/"+arg+"/"+id+".*" );
	 			rm( "/data/backup2/login/"+arg+"/"+id+".*" );
	 			rm( "/data/sig/"+arg+"/"+id+".*" );
	 			rm( "/data/mail/"+arg+"/"+id+".*" );	 			
	 			count++;
			}
			destruct( ob );
		}
	}
	reclaim_objects();

        write( "\n\n原來 ID 以 " + arg + " 開頭的玩家, 總共有 " + sum + " 位。\n" );
        write( "其中 "+ count +" 位超過 "+ DAY +" 天未上線的玩家, 已被系統清除掉了。\n" );
        write( "現在總共剩下 " + ( sum-count ) + " 位玩家。\n" );

	return sum-count;
}	

int help( object me )
{
	write(@TEXT

	auto [英文字母(a~z)]
	
	範例: auto c 		清查 ID 以 c 開頭的玩家
	      auto all  	清查全部玩家
	      auto count	計算玩家資料總數

	清除 ID 以 (a~z) 開頭, 且超過 365 天未上線的玩家。

	為了怕 wiz 使用不當, 便沒有讓 wiz 直接輸入天數,
	以防 wiz 操作錯誤, 而不小心將玩家砍除...

						by ACKY
TEXT
	);
	return 1;
}

