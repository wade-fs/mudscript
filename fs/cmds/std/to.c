// to.c

// inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.

int main(object me, string arg)
{ 
      //  me->edit( (: this_object(), ({ "do_to", me, arg }) :) );
        me->edit( (: call_other, __FILE__, "do_to", me, arg :) );
        return 1;
}

void do_to(object me, string arg, string str)
{
        seteuid(getuid());
        if(arg) me->force_me(arg + " " + str);
        else me->force_me(str);
}

int help (object me)
{
  write (@HELP
語法: to <命令>
說明:
      本命令通常用 say, chat, rumor 等等命令上, 可以讓您一次
    把多行的訊息說完. 底下舉例說明一下:

    to say  *按 enter*
    ...
    ...
    ...
    .

    上面點點點是指你的輸入, 一但要結束 to 命令, 可以只按句點 '.'
    這樣就可以達到多行的目的.

    也可以用來唱歌, 如 to music
HELP);
}
