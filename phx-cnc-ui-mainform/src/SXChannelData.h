#ifndef SXCHANNELDATA_H
#define SXCHANNELDATA_H

/*!
	Структура с данными канала.
*/
struct SXChannelData
{
	//! Конструктор.
	SXChannelData() { }

	//! Данныме поля модификатора.
	QString mModify;

	//! Название секции, которой принадлежит канал.
	QString mSectionName;

	//! Название поля, которому принадлежит канал.
	QString mValueName;

	//! Описание.
	QString mDescription;
};

#endif // SXCHANNELDATA_H
