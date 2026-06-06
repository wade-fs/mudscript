// by Alucard 2009/09
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
int transmit2();
void create () {
        set("short","古‧魔法陣");
		set("long", @LONG
                                    .  ''             ''  .
                               . '            .'.            ' .
                           . '          .    .' '.    .          ' .
                        .         . '             .      '' .
                      .'      . '                             ' .      '.
                    .'     .              '                        .     '.
                  .'     .'              '           '              '.     '.
                       .'               '             '               '.
               .     .'                                                 '.    '
              .                      .                   .                .     .
             .  '''''''''''''''''''':''''''''''''''''''''':''''''''''''''''''''  .
            .    ''                .                       .                ''    .
                 ''                                                         ''
           '    '                '                                        .   '    '
          .    .     .          '                             '          .     .    .
                      .        '                               '        .      '    '
                       .                                        '
         .    :             .                                                   :    .
         :    '            .                                       . '          :    :
         :                :                                         :           :    :
         :    .            '                                       ' .          :    :
         '    :             '                                                   '
                       '                                        .      '
                      '        .                               .        '      .    .
          '    '     '          .                             .          '          '
           .    .  .                                                          .    .
                 ..                                         '               ..
            '    ..                '                       '                ..    '
             '  ....................:.....................:....................  '
              '                      '                                    '     '
               '.    '.                                .                .     .
                       '.               .             .               .'
                  '.     '.              .           .              .'     .'
                    '.     '              .                      .       .'
                      '.      ' .                             . '      .'
                          .       '  .      '     '      .  '       .
                           ' .          ''   '. .'   ''          . '
                               ' .            '.'            . '
                                    '  ..             .   '
LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
		set("no_scale",1);
		set("no_chome",1);
        set("light_up",-1);
        set("exits", ([
            "out" :  __DIR__"maze-entrance",		
      ]));
        setup();
}

void init()
{
        add_action("do_transmit","time-space");
}

int do_transmit(string str)
{
  object me = this_player();
  int k = me->query_temp("break-sun/transmit");
  if(!me || !k) return 0;
  
  if(str && str == "go")
  {
   if(k < 2)
   {
    write("魔法陣的魔力已消耗殆盡!!\n");
	return 1;
   }
   else if(me->query_temp("transmiting"))
   {
    write("你正在傳送中...\n");
    return 1;
   }
   else {
   message_vision(HIY + "\n魔法陣發出耀眼光芒，四周時空逐漸扭曲......\n" + NOR,me);
   me->start_busy(5);
   me->set_temp("transmiting",1);
   call_out("transmit2",4,me);
       }
  }
  else write("你想在這裡幹什麼!?\n");
  return 1;
}

int transmit2()
{
 object me = this_player();
 me->move(__DIR__"transmit");
 me->add_temp("break-sun/transmit",-1);
 message_vision(HIG + "\n光芒逐漸散去，周圍景象又恢復清晰......\n" + NOR,me);
 me->delete_temp("transmiting");
 return 1;
}

int valid_leave(object me, string dir)
{
if(dir == "out")
if(me->query("break-sun"))
return notify_fail("你體內時空種效力將盡，事不宜遲，趕快回去吧!!\n");
return ::valid_leave(me,dir);
}
