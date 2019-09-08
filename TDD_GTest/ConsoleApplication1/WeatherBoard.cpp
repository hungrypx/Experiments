#include "stdafx.h"
#include "WeatherBoard.h"

CWeatherBoard::CWeatherBoard(Weather* pw)
	{
		weather = std::string("UNKNOWN");
		m_pWeather = pw;
	}

	void CWeatherBoard::UpdateWeather(CLocation* ploc)
	{
		time_t time = GetSystemCurrentTime();
		std::tm tmb;
		localtime_s(&tmb, &time);
		if (tmb.tm_hour != 9)
		{
			UpdateWeatherFromInternet(ploc);
		}
	}

	std::string CWeatherBoard::GetWeather()
	{
		return weather;
	}

	std::time_t CWeatherBoard::GetSystemCurrentTime()
	{
		return m_pWeather->GetCurrentTime();
	}
	void CWeatherBoard::UpdateWeatherFromInternet(CLocation* ploc)
	{
		// network call to get current weather at given location
		weather = m_pWeather->RetrieveWeatherThroughUrl(ploc->GetLocation());
	}
	std::string Weather::RetrieveWeatherThroughUrl(std::string url)
	{
		return std::string();
	}
	std::time_t Weather::GetCurrentTime()
	{
		return std::time_t();
	}
	std::string CLocation::GetLocation()
	{
		return std::string();
	}