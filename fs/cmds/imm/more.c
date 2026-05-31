// cat.c

inherit F_MORE;
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        string file;
        object ob;

        seteuid(geteuid(me));
        if (!arg) return notify_fail("指令格式 : more <檔名>|<物件名> \n");
        file = resolve_path(me->query("cwd"), arg);
        if( file_size(file) < 0 ) {
                ob = present(arg, me);
                if( !ob ) ob = present(arg, environment(me));
                if( !ob ) return notify_fail("沒有這個檔案。\n");
                file = base_name(ob) + ".c";
        }
        me->start_more( read_file(file));
        log_file("wiz/MORE", sprintf("%s(%s) 在%s 觀看檔案%s %s\n"
        ,me->query("name"),me->query("id"),file_name(environment(me)),file, ctime(time()) ));
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : more <檔案>|<物件名>
 
分頁顯示檔案內容。
 
more 模式下的指令:
q      : 離開 more.
b      : 顯示前一頁的內容.
[ENTER]: 顯示下一頁的內容.

HELP
    );
    return 1;
}
