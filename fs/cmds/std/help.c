// help.c

#include <help.h>

inherit F_CLEAN_UP;

string *default_doc_paths = DEFAULT_DOC_PATHS;
string *wiz_doc_paths = WIZ_DOC_PATHS;
string *func_doc_paths = FUNC_DOC_PATHS;

int main(object me, string arg)
{
  int i;
  string file, *search;
  mapping guild;
  string *guild_d;

  seteuid(getuid());

  // 假如沒參數, 則顯示預設的命令
  if( !arg ) {
    cat(HELP_DIR + "help/topics");
    return 1;
  }

  // 增加職業指令 help 
	file="/daemon/class/normal/cmds/"+arg;
	if(file_size(file+".c")>0)
	{
		file->help(me);
		return 1;
	}
  // 看看是否有該命令, 通常命令裡會有 help 訊息
  seteuid(getuid());

  // Support efun/lfun help with same name as other topics such as
  // ed() and ed command.
  if ( sscanf (arg,"%s()",arg)==1 && wizardp(me) && pointerp(func_doc_paths) ) {
    i = sizeof(func_doc_paths);
    while(i--) if( file_size(func_doc_paths[i] + arg)>0 ) {
      me->start_more( read_file(func_doc_paths[i]+arg) );
      return 1;
    }
  }

  if( stringp(file = me->find_command(arg)) ) {
    notify_fail("有 "+arg+" 這個指令存在﹐但是並沒有詳細的說明文件。\n");
    return file->help(me);
  }

  // 搜尋私人的 help 的搜尋路徑
  if( pointerp(search = me->query("help_search_path")) ) {
    i = sizeof(search);
    while(i--) if( file_size(search[i] + arg)>0 ) {
      me->start_more( read_file(search[i] + arg) );
      return 1;
    }
  }

  // 搜尋預設的搜尋路徑, 請看 /include/help.h
  if( pointerp(default_doc_paths) ) {
    i = sizeof(default_doc_paths);
    while(i--) {
      if( file_size(default_doc_paths[i] + arg)>0 ) {
        me->start_more( read_file(default_doc_paths[i] + arg) );
        return 1;
      }
    }
  }

  // 搜尋巫師的搜尋路徑, 請看 /include/help.h
  if( pointerp(wiz_doc_paths) ) {
    i = sizeof(wiz_doc_paths);
    while(i--) if( file_size(wiz_doc_paths[i] + arg)>0 ) {
      me->start_more( read_file(wiz_doc_paths[i]+arg) );
      return 1;
    }
  }
  guild=GUILD_D->query_translate();
  guild_d=keys(guild);
  for(i=0;i<sizeof( guild_d);i++)
  {
	file="/daemon/class/"+guild_d[i]+"/cmds/"+arg;
	if(file_size(file+".c")>0)
	{
		file->help(me);
		return 1;
	}
  }

return notify_fail("沒有針對"+arg+"這項主題的說明文件。\n");
}

int help(object me)
{
	write(@HELP
指令格式 : help <主題>              例如﹕> help cmds
           help <函數名稱>()        例如﹕> help call_out()
指令說明 :
           這個指令提供你針對某一主題的詳細說明文件﹐
           若是不指定主題﹐則提供你有關主題的文件。
HELP
	);
	return 1;
}

