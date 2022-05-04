#ifndef TICKABLE
#define TICKABLE

/// <summary>
/// Interface which defines each tickable game object or component
/// </summary>
class ITickable
{
public:
	bool tick_enabled()const { return tickable; }
	void enable() { tickable = true; }
	void disable() { tickable = false; }

protected:
	virtual void on_update(const float delta_time) = 0;
	virtual void on_fixed_update(const float delta_time) = 0;

private:
	bool tickable = true;
};

#endif // !TICKABLE
