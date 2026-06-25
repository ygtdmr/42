async function sendDelete() {
	const url = document.getElementById('delete-url').value;
	const statusEl = document.getElementById('delete-status');
	statusEl.classList.remove('hidden', 'text-green-400', 'text-red-400');
	statusEl.innerText = "Sending...";
	
	try {
		const response = await fetch(url, { method: 'DELETE' });
		if (response.ok) {
			statusEl.innerText = `Success! Status: ${response.status}`;
			statusEl.classList.add('text-green-400');
		} else {
			statusEl.innerText = `Failed! Status: ${response.status}`;
			statusEl.classList.add('text-red-400');
		}
	} catch (error) {
		statusEl.innerText = `Network Error!`;
		statusEl.classList.add('text-red-400');
	}
	statusEl.classList.remove('hidden');
}

async function testMethodNotAllowed() {
	// Sending a POST request to a route that presumably only accepts GET
	const statusEl = document.getElementById('error-status');
	try {
		const response = await fetch('/', { method: 'POST', body: 'test' });
		statusEl.innerText = `Received Status: ${response.status}`;
		statusEl.className = 'mt-3 text-center text-sm font-bold ' + (response.status === 405 ? 'text-green-400' : 'text-red-400');
	} catch (error) {
		statusEl.innerText = `Network Error!`;
		statusEl.className = 'mt-3 text-center text-sm font-bold text-red-400';
	}
	statusEl.classList.remove('hidden');
}

async function testLargePayload() {
	// Generate a large payload (e.g., 5MB string) to test client_max_body_size
	const statusEl = document.getElementById('error-status');
	statusEl.innerText = "Generating large payload & sending...";
	statusEl.className = 'mt-3 text-center text-sm font-bold text-yellow-400';
	statusEl.classList.remove('hidden');

	const largeData = "A".repeat(5 * 1024 * 1024); // 5 MB of 'A's
	
	try {
		const response = await fetch('/upload', { 
			method: 'POST', 
			headers: { 'Content-Type': 'text/plain' },
			body: largeData 
		});
		statusEl.innerText = `Received Status: ${response.status} (Expected 413)`;
		statusEl.className = 'mt-3 text-center text-sm font-bold ' + (response.status === 413 ? 'text-green-400' : 'text-orange-400');
	} catch (error) {
		statusEl.innerText = `Network Error / Connection Closed by Server`;
		// A network error here often means the server abruptly closed the connection due to size, which is also a valid C++ webserver behavior.
		statusEl.className = 'mt-3 text-center text-sm font-bold text-green-400';
	}
}