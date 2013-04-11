#ifndef _IMESSAGECONSTANTS_H_INCLUDED_

#define _IMESSAGECONSTANTS_H_INCLUDED_

#include <string>

namespace Commands
{
//сообщение имеет вид: section#name#value$section#name#value$...\n
//name от ядра имеют префикс state и называются состояниями
//name от формы имеют прификс cmd и называются  командами
    const std::string DELIMITER = "$";
    const std::string SIMPLE_DELIMITER = "#";
    const std::string END_OF_MESSAGE = "\n";
//    const std::string MSG_STATE_PREFIX = "state_";
    const std::string MSG_CMD_PREFIX = "cmd_";

    //общие значения
    const std::string MSG_VALUE_OFF = "off";
    const std::string MSG_VALUE_ON = "on";
    const std::string MSG_VALUE_REEVENT = "reevent";
    const std::string MSG_VALUE_INVERT = "invert";
    const std::string MSG_VALUE_INC = "inc";
    const std::string MSG_VALUE_DEC = "dec";
    const std::string MSG_VALUE_ZERO = "0";
    const std::string MSG_VALUE_AUTO = "auto";
    const std::string MSG_VALUE_STOP = "stop";

////////////////////////////////////////////////////////////////////////////////
  //Общие для драйверов ввода/вывода future
    const std::string MSG_SECTION_IO = "IO";

    const std::string MSG_CMD_SET_VALUE = "cmd_value_";
    const std::string MSG_STATE_GET_VALUE = "state_value_";
    const std::string MSG_STATE_RECV_VALUE = "state_recv_";
////////////////////////////////////////////////////////////////////////////////
//сообщения при старте формы/ядра 
    const std::string MSG_SECTION_START = "start";
	//выкл всё - по кнопке "Выкл УЧПУ"
    const std::string MSG_CMD_SHUTDOWN = "cmd_shutdown";
    //const std::string MSG_CMD_REBOOT = "cmd_reboot";
    //const std::string MSG_CMD_RESTART = "cmd_restart";
	//рестарт формы, после того как форма стартанула
    const std::string MSG_CMD_FORM_RESTART = "cmd_form_restart";
    //const std::string MSG_CMD_START_UTILS = "cmd_start_utils";

////////////////////////////////////////////////////////////////////////////////
//
	//команды/состояния режима "Управление"
    const std::string MSG_SECTION_OPERATOR = "oper";
	//Кнопка "Стоп", значение =0
    const std::string MSG_CMD_STOP_OPERATION = "cmd_stop_operation";
	//
    const std::string MSG_CMD_CONTINUE_OPERATION = "cmd_continue_operation";
	
	//Кнопка "Управление"  - добавить кнопку в верхнуюю полосу, прижать влево
    const std::string MSG_CMD_CONTROL = "cmd_control";//значения:MSG_VALUE_INVERT
	//состояние ядра - меняем цвет кнопки: on=Зеленый,off-безцвет
    const std::string MSG_STATE_CONTROL = "state_control";//значения:MSG_VALUE_ON/OFF

//Управление со стороны Перемещений(слева)
	//Кнопки "Вперед/Назал/Выход", со значениями: MSG_VALUE_FORWARD, MSG_VALUE_BACKWARD, MSG_VALUE_FIND_TRJ - см ниже
    const std::string MSG_CMD_RUN_CP = "cmd_run_cp";
    const std::string MSG_STATE_RUN_CP = "state_run_cp";
    const std::string MSG_STATE_STOP_CP = "state_stop_cp";

    //0: stop(hand), 1: forward, 2: backward, 3: findTrj
    const std::string MSG_VALUE_HAND = "hand";
    const std::string MSG_VALUE_FORWARD = "forward";
    const std::string MSG_VALUE_BACKWARD = "backward";
    const std::string MSG_VALUE_FIND_TRJ = "find_trj";
	
	//тек кадр, добавить box "Текущий кадр" в подрежим "Вперед/Назал/Выход", отображать значения value
    const std::string MSG_STATE_CP_LINE = "state_CPLine";
    
    //"Покадрово", добавить кнопку F3
    const std::string MSG_CMD_MODE_BY_STEP = "cmd_mode_by_step";
    const std::string MSG_STATE_MODE_BY_STEP = "state_by_step";//on - зеленым
	
	//"Зацикленно", добавить кнопку F4
    const std::string MSG_CMD_MODE_LOOP = "cmd_mode_loop";
    const std::string MSG_STATE_MODE_LOOP = "state_loop";//on - зеленым

    //диалог "Перехать"(там где абс/относ), значение <цифра>
    const std::string MSG_CMD_FROM_STEP = "cmd_from_step";
    const std::string MSG_CMD_GOTO_STEP = "cmd_goto_step";
    const std::string MSG_CMD_FROM_BURN = "cmd_from_burn";
    const std::string MSG_CMD_GOTO_BURN = "cmd_goto_burn";
	
	//Сброс координат, добавить кнопку F7
    const std::string MSG_CMD_RESET_POS = "cmd_reset_pos";

	//Загрузка УП на отработку, по диалогу "Загрузить"
    const std::string MSG_CMD_LOAD_CP = "cmd_load_cp";
//////////////////////////////////////////////////////////////////////
	//секция Move перемещения, элементы со стороны Перемещений(слева)
    const std::string MSG_SECTION_MOVE = "MM";
	//позиции осей, в поле X|Y в отражениии плота, все позициив микрометрах
    const std::string MSG_STATE_POS_AXIS = "pos_axis";
	//формат 0=1234,1=2345,... 1.234мм, 2.345мм, но отражать до 0.1мм
    
	//Коррекция скорости +/- значения +1 или -1 */
    const std::string MSG_CMD_FEED = "cmd_feed";
    const std::string MSG_STATE_FEED_RESULT = "state_feed_result"; //тек скорость, в поле F, скорость в мкрм/мин, но отражать в мм/мин
    const std::string MSG_STATE_FEED_PERCENTAGE = "state_feed_percentage"; //future
	
	//Режим работы скорости: команды с полосы скорости, значения
    const std::string MSG_CMD_MODE_FEED = "cmd_mode_feed";
    const std::string MSG_STATE_MODE_FEED = "state_mode_feed";
    const std::string MSG_VALUE_NORMAL = "0";
    const std::string MSG_VALUE_FAST = "1";
    const std::string MSG_VALUE_SLOW = "2";
	//полоса меняет значения от состояний ядра и собств команд(как сейчас)
	
    // Ручное абсолютное перемещение. Пример значения= 0=12345,1=23456 - движение в поз XY=[12.345мм:23.456мм]
    const std::string MSG_CMD_HAND_ABSOLUTE_MOVING = "cmd_hand_absolute_moving";
    // Ручное относительное перемещение. Пример значения= 0=12345,1=23456 - движение в поз XY=[12.345мм:23.456мм]
    const std::string MSG_CMD_HAND_COMPARATIVE_MOVING = "cmd_hand_comparative_moving";
	
    // Ручное безразмерное перемещение в направлении. По заданию с "круга", Пример значения 0=+1,1=-1 движ в X+,Y-
    const std::string MSG_CMD_HAND_DIR_MOVING = "cmd_hand_dir_moving";
    const std::string MSG_CMD_MOVE_AXIS0F = "0=+1";
    const std::string MSG_CMD_MOVE_AXIS0B = "0=-1";
    const std::string MSG_CMD_MOVE_AXIS0S = "0=0";
    const std::string MSG_CMD_MOVE_AXIS1F = "1=+1";
    const std::string MSG_CMD_MOVE_AXIS1B = "1=-1";
    const std::string MSG_CMD_MOVE_AXIS1S = "1=0";
    const std::string MSG_CMD_MOVE_AXIS2F = "2=+1";
    const std::string MSG_CMD_MOVE_AXIS2B = "2=-1";
    const std::string MSG_CMD_MOVE_AXIS2S = "2=0";
    const std::string MSG_CMD_MOVE_AXIS3F = "3=+1";
    const std::string MSG_CMD_MOVE_AXIS3B = "3=-1";
    const std::string MSG_CMD_MOVE_AXIS3S = "3=0";
    const std::string MSG_CMD_MOVE_AXIS4F = "4=+1";
    const std::string MSG_CMD_MOVE_AXIS4B = "4=-1";
    const std::string MSG_CMD_MOVE_AXIS4S = "4=0";

    const std::string MSG_CMD_MOVE_STOP = "cmd_move_stop"; //стоп перемещениям - кнопка внутри круга

	
//Управление со стороны технологии(справа)
    //секция "управление технологией реза"
    const std::string MSG_SECTION_TECH = "TM";

	//команды по кнопке колонки "Т"
    const std::string MSG_CMD_TS = "cmd_TS";
	// Состояние резака, значение
    const std::string MSG_STATE_TECH = "state_TS";
	//значения формат: <номер кнопки=значение, ...>, кнопки =0,1,2,3
	//значения: 0 - кнопка отжата, без дескрипт
	//			1 - кнопка зажата, написан номер кнопки+1 (те с надписи на кнопках идут с 1)
	//			2 - состояние "горит" - зажата, желтая,надпись: номер кнопки
	//			3 - состояние "режет" - зажата, красная,надпись: номер кнопки
	//			4 - состояние "ищу ноль" - отжата, надпись "Поиск\n0"
	//			5 - состояние "ищу лист" - зажата, надпись "Поиск\nлиста" - можно мелко
	//состояние кнопки изменяется только по приходу от ядра состояний.
	
    const std::string MSG_VALUE_TECH_Zall = "0=";
    const std::string MSG_VALUE_TECH_Z1 = "1=";
    const std::string MSG_VALUE_TECH_Z2 = "2=";
    const std::string MSG_VALUE_TECH_Z3 = "3=";
    const std::string MSG_VALUE_TECH_Z4 = "4=";

    const std::string MSG_VALUE_TECH_DISACT = "0disact";
    const std::string MSG_VALUE_TECH_READY  = "1ready";
    const std::string MSG_VALUE_TECH_FIRE	 = "2fire";
    const std::string MSG_VALUE_TECH_CUT 	 = "3cut";
    const std::string MSG_VALUE_TECH_FZERO	 = "4fzero";
    const std::string MSG_VALUE_TECH_FSHEET = "5fsheet";

// Ручное безразмерное перемещение в направлении Z. По заданию с полосы Z
	const std::string MSG_CMD_HAND_DIR_MOVING_Z = "cmd_hand_dir_moving_Z";
	//значения 0=+1,...  и задаются от направление движения и зажатых кнопок столбца Z
	//Если кнопка не зажата - в команде её значения нет
	//+1:вниз, -1:вверх, 0-стоп, стоп дается всем, в не зависимости от зажатости кнопки

    // Номер пробивки. - future
    const std::string MSG_STATE_CURRENT_BURN = "state_current_burn";
    // Количество пробивок. - future
    const std::string MSG_STATE_COUNT_BURN = "state_count_burn";
	
    //Состояние ожидания выполнения техн операции - future
    const std::string MSG_CMD_WAITING   = "cmd_waiting";
    const std::string MSG_CMD_WAITING_CONTINUE = "cmd_waiting_continue";
    const std::string MSG_CMD_WAITING_BREAK = "cmd_waiting_break";
    const std::string MSG_STATE_WAITING = "state_waiting";//состояние ожидания
    //проценты progress bar, 0%-начало, 100% - конец ожидания
	
    // Технология, значение: тек технология(плазма, микроплазма, кислород, разметка, сверление).
    const std::string MSG_STATE_TECHNOLOGY = "state_technology";
    const std::string MSG_CMD_TECHNOLOGY  = "cmd_technology";
	//в значении приходит имя технологии: Oxy, MPlasma, Plasma, Laser, ... - future

    // Напряжение, в десятых долях вольта. цифры между столцами T и Z, формат 0=123,...
    const std::string MSG_STATE_SVR_VOLTAGE = "state_svr_voltage"; //
	
    //кнопки "Пробивка/Врезка" унести под кнопку Стоп реза (так же как Вперед)
	//На месте расположить кнопки: Указатель,Вытяжка,Резка/Черчение,СВР
    const std::string MSG_CMD_ACTIVATE = "cmd_activate";        //тс включить
    const std::string MSG_CMD_DISACTIVATE = "cmd_disactivate";        //тс выключить
    const std::string MSG_CMD_BURN = "cmd_burn";        //по кнопке пробивка
    const std::string MSG_CMD_R_BURN = "cmd_r_burn";    //по кнопке врезка
    const std::string MSG_CMD_F_BURN = "cmd_f_burn";
    const std::string MSG_CMD_FIRE = "cmd_fire";	     //по кнопке поджечь
    const std::string MSG_CMD_CUT2_OFF = "cmd_tech2off";//по кнопке "стоп реза"
	
	//состояние кнопки "Резка/Черчение" - on=зеленым
    const std::string MSG_STATE_MODE_CUT  = "state_cut";
    const std::string MSG_CMD_MODE_CUT = "cmd_mode_cut";
	//состояние кнопки "Указатель" - on=зеленым
    const std::string MSG_STATE_MODE_POINTER  = "state_marker";
    const std::string MSG_CMD_MODE_POINTER  = "cmd_marker";
	//состояние кнопки "СВР" - on=зеленым
    const std::string MSG_STATE_MODE_SVR  = "state_svr";
    const std::string MSG_CMD_MODE_SVR = "cmd_mode_svr";

    const std::string MSG_CMD_SVR = "cmd_svr_value";


    /*//Команды технологии
    const std::string MSG_CMD_TECH  = "cmd_tech"; //команда технологии
    const std::string MSG_CMD_TECH0  = MSG_CMD_TECH+"0"; //поиск листа
    const std::string MSG_CMD_TECH1  = MSG_CMD_TECH+"1";//поджиг
    const std::string MSG_CMD_TECH21 = MSG_CMD_TECH+"21"; //пробивка
    const std::string MSG_CMD_TECH22 = MSG_CMD_TECH+"22"; //поджиг
    const std::string MSG_CMD_TECH23 = MSG_CMD_TECH+"23"; //пробивка
    const std::string MSG_CMD_TECH24 = MSG_CMD_TECH+"24"; //пробивка
    const std::string MSG_CMD_TECH25 = MSG_CMD_TECH+"25"; //пробивка
    const std::string MSG_CMD_TECH21Off = MSG_CMD_TECH+"21Off"; //выкл реза
    const std::string MSG_CMD_TECH22Off = MSG_CMD_TECH+"22Off"; //
    const std::string MSG_CMD_TECH23Off = MSG_CMD_TECH+"23Off"; //выкл реза с ходу

    const std::string MSG_CMD_TECH_Z_STOP = MSG_CMD_TECH+"Z_stop"; //
    const std::string MSG_CMD_TECH_Z_AUTO = MSG_CMD_TECH+"Z_auto"; //
    const std::string MSG_CMD_TECH_Z_PARK = MSG_CMD_TECH+"Z_park"; //
    const std::string MSG_CMD_TECH_Z_UP = MSG_CMD_TECH+"_Z_up"; //
    const std::string MSG_CMD_TECH_Z_UP_CORRECT = MSG_CMD_TECH+"_Z_up_correct"; //
    const std::string MSG_CMD_TECH_Z_DOWN = MSG_CMD_TECH+"_Z_down"; //
    const std::string MSG_CMD_TECH_Z_DOWN_CORRECT = MSG_CMD_TECH+"_Z_down_correct"; //
*/
    /////////////////////////////////////////////////////////////////////////////
	//секция параметры
    const std::string MSG_SECTION_PARAMS = "section_params";
	//ядро просит перечитать параметры
    const std::string MSG_STATE_RELOAD_PARAMS = "state_reload_params";
	//форма просит перечитать параметры
    const std::string MSG_CMD_RELOAD_PARAMS = "cmd_reload_params";

  //ядро просит перечитать параметры
    const std::string MSG_STATE_REFRESH_PARAMS = "state_refresh_params";
  //форма просит перечитать параметры
    const std::string MSG_CMD_REFRESH_PARAMS = "cmd_refresh_params";


    ////////////////////////////////////////////////////////////////////////////////
  //Общие информативные сообщения и аварии, отображаются в поле text режима "Управления"
    const std::string MSG_SECTION_ALARM = "alarm";

    const std::string MSG_STATE_MULTI_ALARM = "state_multi_alarm";
	//отобразить value как строку сообщения
	
    const std::string MSG_STATE_MULTI_ALARM_ADD
                                  = "state_multi_alarm_add";
    const std::string MSG_STATE_MULTI_ALARM_REMOVE
                                  = "state_multi_alarm_remove";
	//добавить/удалить value в строку сообщения

    const std::string MSG_STATE_INFO_ALARM = "state_info_alarm";
	//отобразить сообщение в верхней полосе, в верхнюю полосу добавить кнопку, прижать вправо
	//сброс аварий, по нажатию на кнопку в верхней полосе
    const std::string MSG_CMD_RESET_ALARMS = "cmd_reset_alarms";
	
    //const std::string MSG_STATE_RESET_ALARMS = "state_reset_alarms";

    //const std::string MSG_STATE_INFO = "state_info";
    //const std::string MSG_STATE_STATUS = "state_status";
    
    const std::string MSG_CMD_RED_BUTTON = "red_button";
    
//////////////////////////////////////////////////////////////////////////////////
//future
    const std::string MSG_SECTION_CART = "section_cart";
    const std::string MSG_STATE_CART = "state_cart";
    const std::string MSG_CMD_CART = "cmd_cart";
//    const std::string MSG_SECTION_UTILITY = "utility";
//
//
//////////////////////////////////////////////////////////////////////////////////
//
//    /** Готовность к отработке УП. */
//    //const std::string MSG_STATE_CP_READY = "state_cp_ready";
//    const std::string MSG_CMD_DEBUG_ON_OFF = "cmd_debug_on_off";
//
//
    /////////////////////////////////////////////////////////////////////////////////////
    //

  
    //секция "управление газ. консоль" future
    const std::string MSG_SECTION_GC = "GC";
    const std::string MSG_CMD_GC_RELOAD = "cmd_gc_reload"; //перегрузить давления    //секция "управление газ. консоль"
    
    const std::string MSG_CMD_GC_KM  = "cmd_gc_KM";
    const std::string MSG_CMD_GC_KP  = "cmd_gc_KP";
    const std::string MSG_CMD_GC_KPV = "cmd_gc_KPV";
    const std::string MSG_CMD_GC_KR  = "cmd_gc_KR";
    const std::string MSG_CMD_GC_KRV = "cmd_gc_KRV";
    const std::string MSG_CMD_GC_GG  = "cmd_gc_GG";
    const std::string MSG_CMD_GC_GGV = "cmd_gc_GGV";
    
    //1=123,2=234,3=456,4=678
    const std::string MSG_CMD_GC_KP1 = "cmd_gc_KP1";
    const std::string MSG_CMD_GC_KR1 = "cmd_gc_KR1";
    const std::string MSG_CMD_GC_GG1 = "cmd_gc_GG1";

    const std::string MSG_CMD_GC_KP2 = "cmd_gc_KP2";
    const std::string MSG_CMD_GC_KR2 = "cmd_gc_KR2";
    const std::string MSG_CMD_GC_GG2 = "cmd_gc_GG2";

    const std::string MSG_CMD_GC_KP3 = "cmd_gc_KP3";
    const std::string MSG_CMD_GC_KR3 = "cmd_gc_KR3";
    const std::string MSG_CMD_GC_GG3 = "cmd_gc_GG3";

    const std::string MSG_CMD_GC_KP4 = "cmd_gc_KP4";
    const std::string MSG_CMD_GC_KR4 = "cmd_gc_KR4";
    const std::string MSG_CMD_GC_GG4 = "cmd_gc_GG4";
}
using namespace Commands;
#endif
