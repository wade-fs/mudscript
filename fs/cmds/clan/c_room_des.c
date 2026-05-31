// c_room_des.c by ACKY
inherit F_CLEAN_UP;

#include <clanf.h>

string filename, file;

void set_long( object me, string str );
int help( object me );
int filter_wiz(object wiz);

int main( object me, string arg )
{
	object env;
	seteuid(getuid());
	if( !me->query("clan") ) return 0;
	if( arg != "here" )      return help(me);
	if( !CLAN_D->is_clan_room(me) )
		return notify_fail( "此區域並非本幫所屬地盤。\n" );
	env = environment(me);
	if( env->query("owner") != me->query("id") && me->query("clan/rank") > 3 )
		return notify_fail( "此處並非您的區域。\n" );
	filename = base_name(env) + ".c";
	file = read_file(filename);
	write( "是否更改短敘述? [N] : " );
	input_to( "ask_short", 0, me );
	return 1;
}

void ask_short( string str, object me )
{
	if( !strlen(str) || ( str[0] != 'y' && str[0] != 'Y' ) ) {
		write( "是否更改長敘述? [N] : " );
		input_to( "ask_long", 0, me );
		return;
	}
	write( "請輸入短敘述: " );
	input_to( "set_short", 0, me );
}

void set_short( string str, object me )
{
	string *strs;
        object *user;
	int i;

	if( !strlen(str) ) {
		write( "\n請輸入短敘述: " );
		input_to( "set_short", 0, me );
		return;
	}
        if( strsrch(str,"(") != -1 && strsrch(str,")") != -1 && strsrch(str,"->") != -1 && strsrch(str,"//") != -1 && strsrch(str,";") != -1 && strsrch(str,"\"") != -1 && strsrch(str,"_") != -1 )
        {  
           user = users();
           user = filter_array(user,"filter_wiz",this_object());
           me->set("startroom","/open/wiz/courthouse");
           tell_object(user,sprintf("【系統】警告：%s(%s)使用幫派指令c_room_des嘗試製造bug，指令為：%s\n",me->name(1),me->query("id"),str));
           write_file("/log/clan/des",sprintf("%s(%s) 嘗試製造bug將房間名稱改成 %s 於 %s\n",me->name(1),me->query("id"),str,ctime(time())));
           write( "\n輸入格式錯誤，請輸入短敘述: " );
           input_to( "set_short", 0, me );
           return;
        }

	strs = explode( file, "\n" );
	for( i=0; i<sizeof(strs); i++ )
		if( strsrch( strs[i], "\"short\"") != -1 ) break;
	strs[i] = "\tset( \"short\", \"" + str + "\" );";
	file = implode( strs, "\n" ) + "\n";
	write_file("/log/clan/des",sprintf("%s(%s) 將房間短名稱改成 %s 於 %s\n",me->name(1),me->query("id"),str,ctime(time())));
	write( "\n是否更改長敘述? [N] : " );
	input_to( "ask_long", 0, me );
}

int filter_wiz(object wiz)
{
  if(wizardp(wiz)) return 1;
  return 0;
}

void ask_long( string str, object me )
{
	if( !strlen(str) || ( str[0] != 'y' && str[0] != 'Y' ) ) {
		write_file( filename, file, 1 );
		C_ROOM->update_keep( filename );
		write( "OK.\n" );
		return ;
	}
	write( "請輸入長敘述: " );
	me->edit( (: set_long, me :) );
}

void set_long( object me, string str )
{
	string *strs;
	int i, a, b;

	if( strlen(str) < 200 ) {
		write( "你輸入的敘述太少了，再寫多一點吧。\n" );
		write( "請輸入長敘述:" );
		me->edit( (: set_long, me :) );
		return;
	}

	strs = explode( file, "\n" );
	for( i=0; i<sizeof(strs); i++ )
		if( strsrch( strs[i], "@LONG" ) != -1 ) a = i;
		else if( strsrch(strs[i], "LONG);" ) != -1 ) {
			b = i;
			break;
		}
	file = implode( strs[0..a], "\n" ) + "\n" + replace_string( str, "\"", " " ) + implode( strs[b..<0], "\n" ) + "\n";

	write_file( filename, file, 1 );
	C_ROOM->update_keep( filename );
	write( "OK.\n" );
}

int help( object me )
{
	write( @HELP
指令格式: c_room_des here
指令說明: 修改目前所處區域之敘述。
	  除了階級三之外, 也可自行修改自己的區域。

						by ACKY 08/17/2000
HELP);
	return 1;
}
