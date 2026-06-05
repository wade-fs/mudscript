// save.c
// 增加備份檔的儲存
// by wade (1996 6 6)
inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string arg)
{
    string id, src, dst ,room_name;
	// object link_ob, env=environment(me);
	object link_ob, env;

	seteuid(getuid());
	env = environment(me);

	if(env) room_name=file_name(env);
	if( !objectp(link_ob = me->query_temp("link_ob")) ) {
		// return notify_fail("你不是經由正常連線進入﹐不能儲存。\n");
		me->set_temp( "link_ob", me );
		link_ob = me;
	}
	if( me->save() ) {
		if( env->query("valid_startroom") ) {
			me->set( "startroom", base_name(env) );
			write( HIW + "當你下次連線進來時﹐將從此處進入狂想空間。\n" + NOR );
		}
		else if( me->query("clan") )
			if( base_name(env) == CLAN_D->clan_query( me->query("clan/id"), "home" ) ) {
				me->set( "startroom", base_name(env) );
				write( HIW + "當你下次連線進來時﹐將從此處進入狂想空間。\n" + NOR );
			}
		write( HIY + "檔案儲存完畢。\n請記得以 save -1 或 save -2 備份檔案。\n" + HIC + "請隨時以 help news 來觀看狂想之任何最新異動。:)\n" + NOR );
	}
	else return notify_fail( "\n\t存檔失敗...\n\n" );
	if( me != link_ob )
		link_ob->save();
	id = me->query("id");
	seteuid(ROOT_UID);
	src = sprintf( "/data/user/%s/%s.o", id[0..0], id );
	dst = sprintf( "/data/backup/user/%s", id[0..0] );
	if( file_size(dst) != -2 ) // 目錄傳回 -2，空檔或不在傳回 -1
	mkdirs(dst); // 新增的，會自動一層一層 mkdir
	dst += "/" + id + ".o";
	if( !cp( src, dst ) )
		return notify_fail( "無法備份您的資料檔.\n" );
	src = sprintf( "/data/login/%s/%s.o", id[0..0], id );
	dst = sprintf( "/data/backup/login/%s", id[0..0] );
	if( file_size(dst) != -2 )
	mkdirs(dst);
	dst += "/"+id+".o";
	if (!cp (src, dst))
	  return notify_fail("無法備份您的資料檔.\n");

	if (arg == "-1" || arg == "-2") {
	if( me->query("mud_age") < 10800 ) {
	  return notify_fail("你的年紀太小無法備份喔");}
	  src = sprintf ("/data/user/%s/%s.o", id[0..0], id);
	  dst = sprintf ("/data/backup2/user/%s", id[0..0]);
	  if (file_size(dst) != -2)
	    mkdirs(dst);
	  dst += "/"+id+".o";
	  if (!cp (src, dst))
	    return notify_fail("無法備份您的資料檔.\n");
	}

	if (arg == "-1" || arg == "-2") {
	  src = sprintf ("/data/login/%s/%s.o", id[0..0], id);
	  dst = sprintf ("/data/backup2/login/%s", id[0..0]);
	  if (file_size(dst) != -2)
	    mkdirs(dst);
	  dst += "/"+id+".o";
	  if (!cp (src, dst))
	    return notify_fail("無法備份您的資料檔.\n");
	}
	write (HIW + "備份資料 ok.\n" + NOR);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : save [-1|-2]

使用說明 :
	現在系統會不定期幫玩家存基本資料，正如死亡
    的時候會存檔一樣，但是要另外存備份檔的話，現在
    修正為: save -1 會多增加一份備份檔，而 save -2
    則會多第二份備份檔。
	也就是，平常系統會幫你存檔，稱為基本檔，這
    份基本檔常常會發生意外而流失。save -1 則除了基
    本檔之外，還會另存一份備份檔，也就是一次存了兩
    份，而 save -2  則會存成三份。由於讀寫檔案是造
    成 lag  的主要原因之一，因此如非必要，最好別常
    用 save -1，save -2。
	通常，在你一天的最後一次玩的時候才儲存備份
    檔，普通的 save 目前會自動儲存，以免不正常當機
    會造成一天的心血損毀。此外，在 bug  造成損失的
    時候，可以要求用備份檔救回來。也就是說 :
        如果你發現怪怪的時候，請勿使用 save -1，更
    不要使用 save -2 來蓋過資料。否則會把備份檔弄
    壞掉。
HELP
	);
	return 1;
}
