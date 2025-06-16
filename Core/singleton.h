//////////////////////////////////////////////////////////////
//////////////////////  ΩÃ±€≈Ê ≈¨∑°Ω∫  ///////////////////////
//////////////////////////////////////////////////////////////

#pragma once

template <class T>

class singleton
{
private:
	static T *_single;

public:
	singleton()
	{

	};

	virtual ~singleton()
	{
		delete _single;
	};

	static T* getInstance()
	{
		if (_single == NULL)
		{
			_single = new T();
		}

		return _single;
	};
};

template<class T>T* singleton<T>::_single = 0;