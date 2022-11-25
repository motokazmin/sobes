
interface EventListener is
    method update(filename);

class LoggingListener implements EventListener is
	method update(filename);



int main() {
	logger = new LoggingListener();
	emailAlerts = new EmailAlertsListener();

	editor.events.subscribe("open", logger);
	editor.events.subscribe("save", emailAlerts);

	return 0;
}
