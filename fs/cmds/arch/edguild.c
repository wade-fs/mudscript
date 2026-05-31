// edguild.c
// usage: edit guild database.
// author: Spock @ FF	98.Aug.18.
// last modified by Spock @ FF	98.Aug.18.
// related code: /adm/daemons/guildd.c
// note: guild data system is written by fund.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string class, guild, master;

        if( !arg )
		return notify_fail("指令格式﹕edguild <職業英文名稱> <門派中文名稱> <首領中文名稱>\n");

        if( sscanf ( arg,"%s %s %s",class, guild, master) == 3 ) {
		GUILD_D->add_translate( class, guild, master );
		write( "職業: " + class + ", 門派: " + guild + ", 首領: " + master + "\nOk.\n");
                return 1;
        }

        return 0;
}

int help()
{
        write ( @HELP
指令格式﹕edguild <職業英文名稱> <門派中文名稱> <首領中文名稱>
HELP
        );
        return 1 ;
}
