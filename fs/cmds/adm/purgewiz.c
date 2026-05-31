// modify purge.c by ice..

#include <ansi.h>
#define SYNTAX  "指令格式﹕purgewiz [<未上線天數><至少十天>] | <巫師姓名> because <原因> \n       | look [<未上線天數>] <觀看功\能﹐不殺檔>\n"

inherit F_CLEAN_UP;

int do_purge_wizards(int day, int flag);

int main(object me, string arg)
{
        string name, reason;
        int day;
        object ob;

        if( me!=this_player(1) )
                return notify_fail("你沒有權力使用這個指令。\n");

        if( !arg ) return notify_fail(SYNTAX);

        if( sscanf(arg, "%d", day) && day >= 10) return do_purge_wizards(day, 1);

        if( sscanf(arg, "look %d", day) ) return do_purge_wizards(day, 0);
        
        if( sscanf(arg, "%s because %s", name, reason)!=2 )
                return notify_fail(SYNTAX);

        seteuid(getuid());
        if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__)<0 )
                return notify_fail("沒有這位使用者。\n");

        if(SECURITY_D->get_status(name) == "(player)")
                return notify_fail("這個指令只能 purge 巫師。\n");

        if(SECURITY_D->get_status(name) == "(admin)"
           || SECURITY_D->get_status(name) == "(guest)"
           || SECURITY_D->get_status(name) == "(manager)")
                return notify_fail("這個指令不能 purge ADMIN 以上的巫師。\n");

        if(ob=find_player(name))
                destruct(ob);

        SECURITY_D->set_player(name);
        rm(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        rm(DATA_DIR + "user/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        rm(DATA_DIR + "mail/" + name[0..0] + "/" + name + __SAVE_EXTENSION__);
        write( "使用者 " + capitalize(name) + " 刪除掉了。\n");
        log_file("static/PURGE_WIZ", sprintf("[%s] %s purged %s because %s.\n",
                ctime(time())[0..15], geteuid(this_player(1)), name, reason));

        return 1;
}

int do_purge_wizards(int day, int flag)
{
        int i, wiz_cnt, count;
        string *wiz;
        mixed info;

        wiz = sort_array(SECURITY_D->query_wizlist(), 1);
        seteuid(getuid());
        write("\n*** 整理巫師儲存檔中﹐請稍候.... ***\n");
        count=0;
        wiz_cnt=0;
        for(i=0; i<sizeof(wiz); i++)
        {
                wiz_cnt++;
                if(file_size(DATA_DIR + "login/" + wiz[i][0..0] + "/" + wiz[i] + __SAVE_EXTENSION__)<0 )
                {
                        if(flag)
                                SECURITY_D->set_player(wiz[i]);
                        count++;
                        write(wiz[i]+" : "+SECURITY_D->get_status(wiz[i])+" 早已不存在。\n");
                                continue;
                }

                if(SECURITY_D->get_status(wiz[i])=="(manager)" || SECURITY_D->get_status(wiz[i])=="(guest)" || SECURITY_D->get_status(wiz[i])=="(admin)" || SECURITY_D->get_status(wiz[i])=="(arch)")
                                continue;

                info = stat(DATA_DIR + "login/" + wiz[i][0..0] + "/" + wiz[i] + __SAVE_EXTENSION__);
                if( (time()-(int)info[1])/86400 >= day ) {
                        count ++;
                        write(wiz[i]+" : "+SECURITY_D->get_status(wiz[i])+" 已經有 "+(time()-(int)info[1])/86400+" 天沒上線。\n");
                        if(flag)
                        {
                                SECURITY_D->set_player(wiz[i]);
                                rm(DATA_DIR + "login/" + wiz[i][0..0] + "/" + wiz[i] + __SAVE_EXTENSION__);
                                rm(DATA_DIR + "user/" + wiz[i][0..0] + "/" + wiz[i] + __SAVE_EXTENSION__);
                                rm(DATA_DIR + "mail/" + wiz[i][0..0] + "/" + wiz[i] + __SAVE_EXTENSION__);
                        }
                }
        }
        write("\n\n原來總共有 " + wiz_cnt + " 位巫師。\n");
        write( count + " 個超過 " + day + " 天未上線的巫師被清除掉了。\n");
        write("現在總共有 " + (wiz_cnt - count) + " 位巫師。\n");
        if(flag)
        log_file("static/PURGE_WIZ", sprintf("[%s] %s cleaned up %d wizards\n
        \t\t who didn't login for more than %d days\n
        \t\t Resulting statistics: %d wizards remaining.\n",
                ctime(time())[0..15], geteuid(this_player(1)), count, day, wiz_cnt - count));


        return 1;
}

int help()
{
        write(SYNTAX + @TEXT

清除一個巫師或清除超過一定天數(大於十天)不曾上線的巫師。
TEXT
        );
}
